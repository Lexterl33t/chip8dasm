#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../logging/logger.h"
#include "../utils/utils.h"
#include "instruction.h"
#include "instructions.h"

const instruction_t INSTRUCTIONS[] = {
    {.opcode_str = "sys", .nibble = 0x0000, .is_duplicate = true},
    {.opcode_str = "cls", .nibble = 0x00E0, .is_duplicate = true},
    {.opcode_str = "ret", .nibble = 0x00EE, .is_duplicate = true},
    {.opcode_str = "jp", .nibble = 0x0001, .is_duplicate = false},
    {.opcode_str = "call", .nibble = 0x0002, .is_duplicate = false},
    {.opcode_str = "se", .nibble = 0x0003, .is_duplicate = false},
    {.opcode_str = "sne", .nibble = 0x0004, .is_duplicate = false},
    {.opcode_str = "se", .nibble = 0x0005, .is_duplicate = false},
    {.opcode_str = "ld", .nibble = 0x0006, .is_duplicate = false},
    {.opcode_str = "add", .nibble = 0x0007, .is_duplicate = false},
    {.opcode_str = "ld", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "or", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "and", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "xor", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "add", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "sub", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "shr", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "subn", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "shl", .nibble = 0x0008, .is_duplicate = true},
    {.opcode_str = "sne", .nibble = 0x0009, .is_duplicate = false},
    {.opcode_str = "ld", .nibble = 0x000A, .is_duplicate = false},
    {.opcode_str = "jp", .nibble = 0x000B, .is_duplicate = false},
    {.opcode_str = "rnd", .nibble = 0x000C, .is_duplicate = false},
    {.opcode_str = "drw", .nibble = 0x000D, .is_duplicate = false},
    {.opcode_str = "skp", .nibble = 0x000E, .is_duplicate = false},
    {.opcode_str = "sknp", .nibble = 0x000E, .is_duplicate = false},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "add", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true},
    {.opcode_str = "nil", .nibble = 0xFFFF, .is_duplicate = false}};

instruction_t get_instruction_by_nibble(int16_t opcode) {

  uint8_t len_instructions_table =
      sizeof(INSTRUCTIONS) / sizeof(INSTRUCTIONS[0]);

  instruction_t instr;

  for (uint8_t i = 0; i < len_instructions_table; ++i) {

    instr = INSTRUCTIONS[i];

    uint8_t nibble = (opcode & 0xF000) >> 12;
    uint8_t lsb_nibble = opcode & 0x000F;
    uint8_t byte_msb = opcode & 0x00FF;

    printf("Nibble => %d\n", nibble);
    printf("Opcode: %d\n", opcode == instr.nibble);
    if (nibble == 0 && (opcode == instr.nibble)) {
      return instr;
    } else if (nibble == 8) {
      switch (lsb_nibble) {
      case 0x0:
      case 0x1:
      case 0x2:
      case 0x3:
      case 0x4:
      case 0x6:
      case 0x7:
      case 0xE:
        return instr;
      default:
        critical_error(
            "(instructions::get_instruction_by_nibble) : Unknow 0xE msb byte");
      }
    } else if (nibble == 0xE && (opcode == instr.nibble)) {
      switch (byte_msb) {
      case 0x9E:
      case 0xA1:
        return instr;
      default:
        critical_error(
            "(instructions::get_instruction_by_nibble) : Unknow 0xE msb byte");
      }
    } else if (nibble == 0xF && (opcode == instr.nibble)) {
      switch (byte_msb) {
      case 0x07:
      case 0x0A:
      case 0x15:
      case 0x18:
      case 0x1E:
      case 0x29:
      case 0x33:
      case 0x55:
      case 0x65:
        return instr;
      default:
        critical_error(
            "(instructions::get_instruction_by_nibble) : Unknow 0xE msb byte");
      }
    } else if (nibble == instr.nibble) {
      return instr;
    } else {
      critical_error(
          "(instructions::get_instruction_by_nibble) : Unknow Opcode");
    }
  }

  return instr;
}
