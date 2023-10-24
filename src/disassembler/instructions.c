#include <stdint.h>
#include <stdlib.h>

#include "../logging/logger.h"
#include "instruction.h"
#include "instructions.h"

const instruction_t INSTRUCTIONS[] = {
    {.opcode_str = "sys", .nibble = 0x0000},
    {.opcode_str = "cls", .nibble = 0x00E0},
    {.opcode_str = "ret", .nibble = 0x00EE},
    {.opcode_str = "jp", .nibble = 0x0001},
    {.opcode_str = "call", .nibble = 0x0002},
    {.opcode_str = "se", .nibble = 0x0003},
    {.opcode_str = "sne", .nibble = 0x0004},
    {.opcode_str = "se", .nibble = 0x0005},
    {.opcode_str = "ld", .nibble = 0x0006},
    {.opcode_str = "add", .nibble = 0x0007},
    {.opcode_str = "ld", .nibble = 0x0008},
    {.opcode_str = "or", .nibble = 0x0008},
    {.opcode_str = "and", .nibble = 0x0008},
    {.opcode_str = "xor", .nibble = 0x0008},
    {.opcode_str = "add", .nibble = 0x0008},
    {.opcode_str = "sub", .nibble = 0x0008},
    {.opcode_str = "shr", .nibble = 0x0008},
    {.opcode_str = "subn", .nibble = 0x0008},
    {.opcode_str = "shl", .nibble = 0x0008},
    {.opcode_str = "sne", .nibble = 0x0009},
    {.opcode_str = "ld", .nibble = 0x000A},
    {.opcode_str = "jp", .nibble = 0x000B},
    {.opcode_str = "rnd", .nibble = 0x000C},
    {.opcode_str = "drw", .nibble = 0x000D},
    {.opcode_str = "skp", .nibble = 0x000E},
    {.opcode_str = "sknp", .nibble = 0x000E},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "add", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
    {.opcode_str = "ld", .nibble = 0x000F},
};

instruction_t get_instruction_by_nibble(int16_t nibble) {

  return INSTRUCTIONS[0];
}
