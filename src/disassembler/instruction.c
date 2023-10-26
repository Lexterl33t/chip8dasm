#include "instruction.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

instruction_t get_instruction_by_nibble(uint16_t opcode) {

  uint8_t single_operand = (opcode & 0x0F00) >> 8;
  uint8_t second_operand = (opcode & 0x00F0) >> 4;
  uint8_t nibble_operand = (opcode & 0x0FFF);
  uint8_t r_byte_operand = (opcode & 0x00FF);
  uint8_t nibb = (opcode & 0x000F);

  char *op_str = malloc(sizeof(char) * 20);

  instruction_t instr;

  switch (opcode & 0xFFFF) {
  case 0x00E0:
    instr = (instruction_t){.opcode_str = "cls", .nibble = 0x00E0};
    sprintf(op_str, "%s", instr.opcode_str);
    instr.operand_str = op_str;
    return instr;
  case 0x00EE:
    instr = (instruction_t){.opcode_str = "ret", .nibble = 0x00E0};
    sprintf(op_str, "%s", instr.opcode_str);
    instr.operand_str = op_str;
    return instr;
  }

  switch (opcode & 0xF0FF) {
  case 0xE09E:
    instr = (instruction_t){.opcode_str = "skp", .nibble = 0xE09E};
    sprintf(op_str, "%s %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xE0A1:
    instr = (instruction_t){.opcode_str = "sknp", .nibble = 0xE0A1};
    sprintf(op_str, "%s %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF007:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF007};
    sprintf(op_str, "%s %c%d, dt", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF00A:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF00A};
    sprintf(op_str, "%s %c%d, k", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF015:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF015};
    sprintf(op_str, "%s dt, %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF018:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF018};
    sprintf(op_str, "%s st, %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF01E:
    instr = (instruction_t){.opcode_str = "add", .nibble = 0xF01E};
    sprintf(op_str, "%s i, %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF029:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF029};
    sprintf(op_str, "%s f, %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF033:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF033};
    sprintf(op_str, "%s b, %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF055:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF055};
    sprintf(op_str, "%s [i], %c%d", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xF065:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xF065};
    sprintf(op_str, "%s %c%d, [i]", instr.opcode_str, 'v', single_operand);
    instr.operand_str = op_str;
    return instr;
  }

  switch (opcode & 0xF00F) {
  case 0x5000:
    instr = (instruction_t){.opcode_str = "se", .nibble = 0x5000};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8000:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0x8000};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8001:
    instr = (instruction_t){.opcode_str = "or", .nibble = 0x8001};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8002:
    instr = (instruction_t){.opcode_str = "and", .nibble = 0x8002};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8003:
    instr = (instruction_t){.opcode_str = "xor", .nibble = 0x8003};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8004:
    instr = (instruction_t){.opcode_str = "add", .nibble = 0x8004};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8005:
    instr = (instruction_t){.opcode_str = "sub", .nibble = 0x8005};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8006:
    instr = (instruction_t){.opcode_str = "shr", .nibble = 0x8006};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x8007:
    instr = (instruction_t){.opcode_str = "subn", .nibble = 0x8007};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x800E:
    instr = (instruction_t){.opcode_str = "shl", .nibble = 0x800E};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x9000:
    instr = (instruction_t){.opcode_str = "sne", .nibble = 0x9000};
    sprintf(op_str, "%s %c%d, %c%d", instr.opcode_str, 'v', single_operand, 'v',
            second_operand);
    instr.operand_str = op_str;
    return instr;
  }

  switch (opcode & 0xF000) {
  case 0x0000:
    instr = (instruction_t){.opcode_str = "sys", .nibble = 0x0000};
    sprintf(op_str, "%s #%d", instr.opcode_str, nibble_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x1000:
    instr = (instruction_t){.opcode_str = "jp", .nibble = 0x1000};
    sprintf(op_str, "%s #%d", instr.opcode_str, nibble_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x2000:
    instr = (instruction_t){.opcode_str = "call", .nibble = 0x2000};
    sprintf(op_str, "%s #%d", instr.opcode_str, nibble_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x3000:
    instr = (instruction_t){.opcode_str = "se", .nibble = 0x3000};
    sprintf(op_str, "%s %c%d, %d", instr.opcode_str, 'v', single_operand,
            r_byte_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x4000:
    instr = (instruction_t){.opcode_str = "sne", .nibble = 0x4000};
    sprintf(op_str, "%s %c%d, %d", instr.opcode_str, 'v', single_operand,
            r_byte_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x6000:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0x6000};
    sprintf(op_str, "%s %c%d, %d", instr.opcode_str, 'v', single_operand,
            r_byte_operand);
    instr.operand_str = op_str;
    return instr;
  case 0x7000:
    instr = (instruction_t){.opcode_str = "add", .nibble = 0x7000};
    sprintf(op_str, "%s %c%d, %d", instr.opcode_str, 'v', single_operand,
            r_byte_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xA000:
    instr = (instruction_t){.opcode_str = "ld", .nibble = 0xA000};
    sprintf(op_str, "%s i, #%d", instr.opcode_str, nibble_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xB000:
    instr = (instruction_t){.opcode_str = "jp", .nibble = 0xB000};
    sprintf(op_str, "%s #[%d + v0]", instr.opcode_str, nibble_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xC000:
    instr = (instruction_t){.opcode_str = "rnd", .nibble = 0xC000};
    sprintf(op_str, "%s %c%d, %d", instr.opcode_str, 'v', single_operand,
            r_byte_operand);
    instr.operand_str = op_str;
    return instr;
  case 0xD000:
    instr = (instruction_t){.opcode_str = "drw", .nibble = 0xD000};
    sprintf(op_str, "%s %c%d, %c%d, %d", instr.opcode_str, 'v', single_operand,
            'v', second_operand, nibb);
    instr.operand_str = op_str;
    return instr;
  }

  return (instruction_t){.opcode_str = "nil"};
}
