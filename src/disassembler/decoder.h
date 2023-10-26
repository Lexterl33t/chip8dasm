#pragma once

#include "instruction.h"

#define MEMORY_ENTRY_POINT 0x200

instruction_t *decodes(uint16_t *opcodes, uint8_t num_instr);
void free_instructions(instruction_t *instrs);
