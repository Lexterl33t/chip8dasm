#include "decoder.h"
#include "../logging/logger.h"
#include "instruction.h"
#include <stdint.h>
#include <stdlib.h>

instruction_t *decodes(uint16_t *opcodes, uint8_t num_instr) {

  instruction_t *instrs = malloc(num_instr * sizeof(instruction_t));

  if (!instrs) {
    critical_error("(decoder::decodes) : Error allocation instrs");
  }

  for (int i = 0; i < num_instr; ++i) {
    instrs[i] = get_instruction_by_nibble(TO_LITTLE_ENDIAN_16b(opcodes[i]));

    printf("[%04hx] Instruction => %s\n", TO_LITTLE_ENDIAN_16b(opcodes[i]),
           instrs[i].opcode_str);
  }

  return instrs;
}
