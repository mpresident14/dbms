#include "src/disk/disk_manager.hpp"

#include <cerrno>
#include <fstream>

namespace prez::dbms::disk {


absl::Status read(const std::string& filename, uint32_t offset, char* buffer, uint32_t num_bytes) {
  std::ifstream infile(filename);
  infile.seekg(offset);
  if (infile.fail()) {
    return absl::ErrnoToStatus(errno, "Failed to seek in " + filename);
  }

  infile.read(buffer, num_bytes);
  if (infile.fail()) {
    return absl::ErrnoToStatus(errno, "Failed to read " + filename);
  }

  return absl::OkStatus();
}

absl::Status append(const std::string& filename, const char* buffer, uint32_t num_bytes) {
  std::ofstream outfile(filename, std::ios_base::app);
  if (outfile.fail()) {
    return absl::ErrnoToStatus(errno, "Failed to open " + filename);
  }

  outfile.write(buffer, num_bytes);
  if (outfile.fail()) {
    return absl::ErrnoToStatus(errno, "Failed to write to " + filename);
  }

  return absl::OkStatus();
}


} // namespace prez::dbms::disk
