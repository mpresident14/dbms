#ifndef PREZ_DISK_DISK_MANAGER_HPP
#define PREZ_DISK_DISK_MANAGER_HPP

#include <cstdint>
#include <string>

namespace prez::dbms::disk {


void read(const std::string& filename, uint32_t offset, char* buffer, uint32_t num_bytes);

void append(const std::string& filename, const char* buffer, uint32_t num_bytes);


} // namespace prez::dbms::disk

#endif // PREZ_DISK_DISK_MANAGER_HPP
