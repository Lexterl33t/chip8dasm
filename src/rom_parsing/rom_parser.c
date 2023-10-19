#include "rom_parser.h"
#include "../logging/logger.h"
#include "binary_rom_parser.h"

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

rom_t *new_rom(char *binary_path, rom_type_t rom_type) {

  if (!binary_path) {
    critical_error("(rom_parsing::new_rom) : binary_path can't be NULL");
  }

  rom_t *rom_parser = malloc(sizeof(rom_t));

  if (!rom_parser) {
    critical_error("(rom_parsing::new_rom) : Error allocate rom_t");
  }

  rom_parser->binary_path = binary_path;
  rom_parser->type_rom = rom_type;

  return rom_parser;
}

int open_rom(rom_t *rom) {

  if (!rom) {
    critical_error("(rom_parser::open_rom) : rom can't be NULL");
  }

  if ((rom->fd = open(rom->binary_path, O_RDONLY)) < 0) {
    critical_error("(rom_parser::open_rom) : Error opening file descriptor");
  }

  return rom->fd;
}

rom_t *parse_rom(rom_t *rom) {

  printf("type rom: %d\n", rom->type_rom);
  switch (rom->type_rom) {
  case BINARY_ROM:
    rom->rom_bytes = parse_binary_rom(rom->fd);
    break;
  case HEX_ROM:
    break;
  default:
    critical_error("Unknow ROM type");
  }

  return rom;
}
