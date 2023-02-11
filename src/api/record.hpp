#ifndef PREZ_API_RECORD_HPP
#define PREZ_API_RECORD_HPP

#include <any>
#include <cstdint>
#include <cstring>

namespace prez::dbms::api {

enum class ColumnType { BOOL, INT, STRING };

constexpr uint16_t STRING_BYTES = 1024u;
constexpr uint16_t COLUMN_BYTES[] = {1, 4, STRING_BYTES};

uint16_t write_to_buffer(const void* value, ColumnType type, char* buffer) {
  uint16_t num_bytes = COLUMN_BYTES[static_cast<int>(type)];
  std::memcpy(buffer, value, num_bytes);
  return num_bytes;
}

std::any read_from_buffer(ColumnType type, char* buffer) {
  switch (type) {
  case ColumnType::BOOL:
    return std::any(*(bool*)buffer);
  case ColumnType::INT:
    return std::any(*(int*)buffer);
  case ColumnType::STRING:
    return std::make_any<std::string>(buffer, STRING_BYTES);
  }
}

} // namespace prez::dbms::api

#endif // PREZ_API_RECORD_HPP
