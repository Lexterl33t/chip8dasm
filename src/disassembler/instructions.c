#include <stdlib.h>

#include "../logging/logger.h"
#include "instruction.h"
#include "instructions.h"

instructions_t *new_instruction_list() {

  instructions_t *instructions_list = malloc(sizeof(instructions_t));

  if (!instructions_list) {
    critical_error("(instructions::new_instruction_list) : Error allocation "
                   "instructions_list");
  }

  instruction_t *instruction = malloc(sizeof(instruction_t));

  if (!instruction) {
    critical_error(
        "(instructions::new_instruction_list) : Error allocation instruction");
  }

  instruction->next = NULL;
  instruction->nibble = 0;
  instruction->opcode_str = NULL;

  instructions_list->next = instruction;

  return (instructions_list);
}
