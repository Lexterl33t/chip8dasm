#include "binary_rom_parser.h"
#include "../logging/logger.h"

#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>

uint8_t *parse_binary_rom(int fd, uint32_t *num_bytes) {
  struct stat st;

  if (fstat(fd, &st) == -1) {
    critical_error(
        "(binary_rom_parser::parse_binary_rom) : Error getting file size");
  }

  *num_bytes = st.st_size;

  uint8_t *file_addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (file_addr == MAP_FAILED) {
    critical_error("(binary_rom_parser::parse_binary_rom) : Error mmap file");
  }

  return file_addr;
}
