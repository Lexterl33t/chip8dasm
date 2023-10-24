#pragma once

#include <stdint.h>

typedef struct instruction_s {

  char *opcode_str;
  int8_t nibble;
  struct instruction_s *next;
} instruction_t;
