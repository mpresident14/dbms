#include "src/disk/disk_manager.hpp"
#include "src/testing/unit_test.hpp"

#include <fstream>

using namespace prez::unit_test;
namespace disk = prez::dbms::disk;

constexpr char FILENAME[] = "file.data";

BEFORE(setUp) { std::ofstream{FILENAME}; }

AFTER(tearDown) { std::remove(FILENAME); }

TEST(AppendRead_Success) {
  const char outbuf[] = "Hello world";
  char inbuf[7] = {0};

  prez::dbms::disk::append(FILENAME, outbuf, sizeof(outbuf) - 1);
  prez::dbms::disk::read(FILENAME, 2, inbuf, sizeof(inbuf) - 1);

  assertEquals(std::string(inbuf, sizeof(inbuf) - 1), "llo wo");
}

TEST(ReadEof_Throws) {
  const auto& e = assertThrowsType<std::ios_base::failure>([]() {
    char inbuf[20] = {0};
    prez::dbms::disk::read(FILENAME, 2, inbuf, sizeof(inbuf) - 1);
  });
}

TEST(WriteNonexistent_Throws) {
  const auto& e = assertThrowsType<std::ios_base::failure>([]() {
    const char outbuf[] = "Hello world";
    prez::dbms::disk::append("404.data", outbuf, sizeof(outbuf) - 1);
  });
}

int main() { return runTests(); }
