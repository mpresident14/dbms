#ifndef PREZ_API_MANAGER_HPP
#define PREZ_API_MANAGER_HPP

#include "src/api/record.hpp"
#include "src/disk/disk_manager.hpp"

#include <any>
#include <numeric>
#include <string>
#include <vector>

namespace prez::dbms::api {

namespace disk = prez::dbms::disk;

namespace {
constexpr uint16_t MAX_ROW_SIZE = (1 << 16) - 1;
}

std::vector<std::any> read_row(
    const std::string& filename, uint32_t offset, const std::vector<ColumnType>& column_types) {
  // TODO assert len ==
  std::vector<std::any> row;
  row.reserve(column_types.size());

  uint16_t row_size = 0;
  for (ColumnType type : column_types) {
    row_size += COLUMN_BYTES[static_cast<int>(type)];
  }
  char buf[MAX_ROW_SIZE];
  disk::read(filename, offset, buf, row_size);
  char* buf_ptr = buf;
  for (ColumnType type : column_types) {
    row.push_back(read_from_buffer(type, buf_ptr));
    buf_ptr += COLUMN_BYTES[static_cast<int>(type)];
  }
  return row;
}

void write_row(
    const std::string& filename,
    const std::vector<const void*>& record,
    const std::vector<ColumnType>& column_types) {
  // TODO assert len ==
  // TODO: error if column greater than max length (should be enforced during table creation)
  char buf[MAX_ROW_SIZE];
  char* buf_ptr = buf;
  size_t len = record.size();
  for (size_t i = 0; i < len; ++i) {
    buf_ptr += write_to_buffer(record[i], column_types[i], buf_ptr);
  }
  disk::append(filename, buf, buf_ptr - buf);
}

} // namespace prez::dbms::api
#endif // PREZ_API_MANAGER_HPP
