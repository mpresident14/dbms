#include "src/api/manager.hpp"
#include "src/disk/disk_manager.hpp"

#include <iostream>

int main() {
  // const char outbuf[] = "Hello world";
  // auto status =
  //     prez::dbms::disk::append("src/main/testfiles/table.data", outbuf, sizeof(outbuf) - 1);
  // if (!status.ok()) {
  //   std::cout << status << std::endl;
  //   return 1;
  // }

  // char inbuf[7] = {0};
  // status = prez::dbms::disk::read("src/main/testfiles/table.data", 90, inbuf, sizeof(inbuf) - 1);
  // assert(status.ok());

  // std::cout << inbuf << std::endl;
  // if (!status.ok()) {
  //   std::cout << status << std::endl;
  //   return 1;
  // }


  int n = 5678;
  bool b = true;
  std::string str = std::string("Hello world").append(1024, '\0');
  prez::dbms::api::write_row(
      "src/main/testfiles/table.data",
      {&n, &b, str.c_str()},
      {prez::dbms::api::ColumnType::INT,
       prez::dbms::api::ColumnType::BOOL,
       prez::dbms::api::ColumnType::STRING});

  auto row = prez::dbms::api::read_row(
      "src/main/testfiles/table.data",
      0,
      {prez::dbms::api::ColumnType::INT,
       prez::dbms::api::ColumnType::BOOL,
       prez::dbms::api::ColumnType::STRING});


  std::cout << std::any_cast<int>(row[0]) << std::endl;
  std::cout << std::boolalpha << std::any_cast<bool>(row[1]) << std::endl;
  std::cout << std::any_cast<std::string>(row[2]) << std::endl;


  return 0;
}
