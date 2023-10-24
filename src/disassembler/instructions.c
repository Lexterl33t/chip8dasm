#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "../logging/logger.h"
#include "../utils/utils.h"
#include "instruction.h"
#include "instructions.h"
instruction_t get_instruction_by_nibble(uint16_t opcode) {

  uint8_t nibble;
  uint8_t lsb_nibble;
  uint8_t byte_msb;

  nibble = (opcode & 0xF000) >> 12;
  lsb_nibble = opcode & 0x000F;
  byte_msb = opcode & 0x00FF;

  instruction_t instr;

  switch (nibble) {
  case 0x0:
    switch (byte_msb) {
    case 0xEE:
      instr = (instruction_t){
          .opcode_str = "ret", .nibble = 0x00EE, .is_duplicate = true};
      break;
    case 0xE0:
      instr = (instruction_t){
          .opcode_str = "cls", .nibble = 0x00E0, .is_duplicate = true};
      break;
    default:
      instr = (instruction_t){
          .opcode_str = "sys", .nibble = 0x0000, .is_duplicate = true};
      break;
    }
    break;
  case 0x1:
    instr = (instruction_t){
        .opcode_str = "jp", .nibble = 0x0001, .is_duplicate = false};
    break;
  case 0x2:
    instr = (instruction_t){
        .opcode_str = "call", .nibble = 0x0002, .is_duplicate = false};
    break;
  case 0x3:
    instr = (instruction_t){
        .opcode_str = "se", .nibble = 0x0003, .is_duplicate = false};
    break;
  case 0x4:
    instr = (instruction_t){
        .opcode_str = "sne", .nibble = 0x0004, .is_duplicate = false};
    break;
  case 0x5:
    instr = (instruction_t){
        .opcode_str = "se", .nibble = 0x0005, .is_duplicate = false};
    break;
  case 0x6:
    instr = (instruction_t){
        .opcode_str = "ld", .nibble = 0x0006, .is_duplicate = false};
    break;
  case 0x7:
    instr = (instruction_t){
        .opcode_str = "add", .nibble = 0x0007, .is_duplicate = false};
    break;
  case 0x8:
    switch (lsb_nibble) {
    case 0x0:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x1:
      instr = (instruction_t){
          .opcode_str = "or", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x2:
      instr = (instruction_t){
          .opcode_str = "and", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x3:
      instr = (instruction_t){
          .opcode_str = "xor", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x4:
      instr = (instruction_t){
          .opcode_str = "add", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x5:

      instr = (instruction_t){
          .opcode_str = "sub", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x6:
      instr = (instruction_t){
          .opcode_str = "shr", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x7:
      instr = (instruction_t){
          .opcode_str = "subn", .nibble = 0x0008, .is_duplicate = true};
      break;
    case 0x8:
      instr = (instruction_t){
          .opcode_str = "shl", .nibble = 0x0008, .is_duplicate = true};
      break;
    }
    break;
  case 0x9:
    instr = (instruction_t){
        .opcode_str = "sne", .nibble = 0x0009, .is_duplicate = false};
    break;
  case 0xA:
    instr = (instruction_t){
        .opcode_str = "ld", .nibble = 0x000A, .is_duplicate = false};
    break;
  case 0xB:
    instr = (instruction_t){
        .opcode_str = "jp", .nibble = 0x000B, .is_duplicate = false};
    break;
  case 0xC:
    instr = (instruction_t){
        .opcode_str = "rnd", .nibble = 0x000C, .is_duplicate = false};
    break;
  case 0xD:
    instr = (instruction_t){
        .opcode_str = "drw", .nibble = 0x000D, .is_duplicate = false};
    break;
  case 0xE:
    switch (byte_msb) {
    case 0x9E:
      instr = (instruction_t){
          .opcode_str = "skp", .nibble = 0x000E, .is_duplicate = true};
      break;
    case 0xA1:
      instr = (instruction_t){
          .opcode_str = "sknp", .nibble = 0x000E, .is_duplicate = false};
      break;
    }
    break;
  case 0xF:
    switch (byte_msb) {
    case 0x07:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x0A:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x15:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x18:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x1E:

      instr = (instruction_t){
          .opcode_str = "add", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x29:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x33:

      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x55:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    case 0x65:
      instr = (instruction_t){
          .opcode_str = "ld", .nibble = 0x000F, .is_duplicate = true};
      break;
    }
    break;
  }

  return instr;
}
