#include "src/disk/disk_manager.hpp"

#include <cerrno>
#include <fstream>
#include <stdexcept>

namespace prez::dbms::disk {


void read(const std::string& filename, uint32_t offset, char* buffer, uint32_t num_bytes) {
  std::ifstream infile(filename);
  infile.exceptions(std::ios_base::eofbit | std::ios_base::badbit | std::ios_base::failbit);
  infile.seekg(offset);
  infile.read(buffer, num_bytes);
}

void append(const std::string& filename, const char* buffer, uint32_t num_bytes) {
  std::ofstream outfile(filename, std::ios_base::in | std::ios_base::ate);
  outfile.exceptions(std::ios_base::badbit | std::ios_base::failbit);
  outfile.write(buffer, num_bytes);
}


} // namespace prez::dbms::disk
