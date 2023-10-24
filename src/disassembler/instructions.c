#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "../logging/logger.h"
#include "../utils/utils.h"
#include "instruction.h"
#include "instructions.h"

instruction_t get_instruction_by_nibble(uint16_t opcode) {

  switch (opcode & 0xFFFF) {
  case 0x00E0:
    return (instruction_t){.opcode_str = "cls", .nibble = 0x00E0};
  case 0x00EE:
    return (instruction_t){.opcode_str = "ret", .nibble = 0x00E0};
  }

  switch (opcode & 0xF0FF) {
  case 0xE09E:
    return (instruction_t){.opcode_str = "skp", .nibble = 0xE09E};
  case 0xE0A1:
    return (instruction_t){.opcode_str = "sknp", .nibble = 0xE0A1};
  case 0xF007:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF007};
  case 0xF00A:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF00A};
  case 0xF015:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF015};
  case 0xF018:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF018};
  case 0xF01E:
    return (instruction_t){.opcode_str = "add", .nibble = 0xF01E};
  case 0xF029:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF029};
  case 0xF033:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF033};
  case 0xF055:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF055};
  case 0xF065:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xF065};
  }

  switch (opcode & 0xF00F) {
  case 0x5000:
    return (instruction_t){.opcode_str = "se", .nibble = 0x5000};
  case 0x8000:
    return (instruction_t){.opcode_str = "ld", .nibble = 0x8000};
  case 0x8001:
    return (instruction_t){.opcode_str = "or", .nibble = 0x8001};
  case 0x8002:
    return (instruction_t){.opcode_str = "and", .nibble = 0x8002};
  case 0x8003:
    return (instruction_t){.opcode_str = "xor", .nibble = 0x8003};
  case 0x8004:
    return (instruction_t){.opcode_str = "add", .nibble = 0x8004};
  case 0x8005:
    return (instruction_t){.opcode_str = "sub", .nibble = 0x8005};
  case 0x8006:
    return (instruction_t){.opcode_str = "shr", .nibble = 0x8006};
  case 0x8007:
    return (instruction_t){.opcode_str = "subn", .nibble = 0x8007};
  case 0x800E:
    return (instruction_t){.opcode_str = "shl", .nibble = 0x800E};
  case 0x9000:
    return (instruction_t){.opcode_str = "sne", .nibble = 0x9000};
  }

  switch (opcode & 0xF000) {
  case 0x0000:
    return (instruction_t){.opcode_str = "sys", .nibble = 0x0000};
  case 0x1000:
    return (instruction_t){.opcode_str = "jp", .nibble = 0x1000};
  case 0x2000:
    return (instruction_t){.opcode_str = "call", .nibble = 0x2000};
  case 0x3000:
    return (instruction_t){.opcode_str = "se", .nibble = 0x3000};
  case 0x4000:
    return (instruction_t){.opcode_str = "sne", .nibble = 0x4000};
  case 0x6000:
    return (instruction_t){.opcode_str = "ld", .nibble = 0x6000};
  case 0x7000:
    return (instruction_t){.opcode_str = "add", .nibble = 0x7000};
  case 0xA000:
    return (instruction_t){.opcode_str = "ld", .nibble = 0xA000};
  case 0xB000:
    return (instruction_t){.opcode_str = "jp", .nibble = 0xB000};
  case 0xC000:
    return (instruction_t){.opcode_str = "rnd", .nibble = 0xC000};
  case 0xD000:
    return (instruction_t){.opcode_str = "drw", .nibble = 0xD000};
  }

  return (instruction_t){.opcode_str = "nil"};
}
