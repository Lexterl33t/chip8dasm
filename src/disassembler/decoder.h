#pragma once

#include "instruction.h"

instruction_t *decodes(uint16_t *opcodes, uint8_t num_instr);
