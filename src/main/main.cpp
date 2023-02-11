#include "src/disk/disk_manager.hpp"

#include <iostream>

int main() {
  const char outbuf[] = "Hello world";
  auto status =
      prez::dbms::disk::append("src/main/testfiles/table.data", outbuf, sizeof(outbuf) - 1);
  if (!status.ok()) {
    std::cout << status << std::endl;
    return 1;
  }

  char inbuf[7] = {0};
  status = prez::dbms::disk::read("src/main/testfiles/table.data", 1, inbuf, sizeof(inbuf) - 1);
  assert(status.ok());

  std::cout << inbuf << std::endl;
  if (!status.ok()) {
    std::cout << status << std::endl;
    return 1;
  }

  return 0;
}
