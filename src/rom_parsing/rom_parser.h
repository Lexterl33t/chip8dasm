#pragma once

#include <stdint.h>
#include <stdio.h>

typedef enum { BINARY_ROM, HEX_ROM } rom_type_t;

typedef struct {
  char *binary_path;
  int fd;
  int number_instr;
  uint32_t num_bytes;
  rom_type_t type_rom;
  uint8_t *rom_bytes;
} rom_t;

rom_t *new_rom(char *binary_path, rom_type_t rom_type);
int open_rom(rom_t *rom);
rom_t *parse_rom(rom_t *rom);
int rom_count_instruction(rom_t *rom);
