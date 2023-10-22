#pragma once

#include <stdint.h>

typedef struct instruction_s {

  char *opcode_str;
  int8_t nibble;
  instruction_s *next;
} instruction_t;
