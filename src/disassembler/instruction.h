#pragma once

#include "../utils/utils.h"
#include <stdint.h>

typedef struct {

  char *opcode_str;
  int16_t nibble;

} instruction_t;

instruction_t get_instruction_by_nibble(uint16_t opcode);
