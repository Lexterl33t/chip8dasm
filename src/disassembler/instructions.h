#pragma once

#include "instruction.h"

#define FOREACH_INSTRUCTION(instr, code)                                       \
  while (instr) {                                                              \
    code;                                                                      \
    instr = instr->next;                                                       \
  }

typedef struct {
  instruction_t *next;
} instructions_t;

instructions_t *new_instructions_list();
instruction_t *get_instruction_by_nibble(int8_t nibble);
