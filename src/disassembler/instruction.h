#pragma once

#include "../utils/utils.h"
#include <stdint.h>

typedef struct {
  char *opcode_str;
  char *operand_str;
  int16_t nibble;
  uint64_t pc;
} instruction_t;

instruction_t get_instruction_by_nibble(uint16_t opcode);
instruction_t opcode_to_string(instruction_t instr);
