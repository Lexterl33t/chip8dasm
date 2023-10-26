
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argparser/argparser.h"
#include "argparser/errors.h"
#include "disassembler/decoder.h"
#include "disassembler/instruction.h"
#include "rom_parsing/rom_parser.h"
#include "utils/utils.h"

int main(int argc, char **argv) {

  instruction_t *instrs;

  argument_parser_t *parser = new_parser(
      "Chip8Dasm", "Chip8 disassembler from scratch @Lxt3h", "", argv, argc);

  add_argument(parser, STRING, "--disassemble",
               "Take ROM binary and print instructions", true);

  add_argument(parser, STRING, "--show-type",
               "Take <graph, linear> string to get type view", true);

  parse_args(parser);

  if (argument_exist(parser, "--disassemble")) {

    argument_t *binary_path = get_argument(parser, "--disassemble");

    rom_t *rom_parser = new_rom(binary_path->data.str, BINARY_ROM);
    open_rom(rom_parser);
    parse_rom(rom_parser);

    instrs = decodes(rom_parser->rom_bytes, rom_parser->number_instr);

    if (argument_exist(parser, "--show-type")) {

      argument_t *view_type = get_argument(parser, "--show-type");

      if (!strncmp(view_type->data.str, "linear", strlen("linear"))) {
        printf("Tu as choisis la linear view");
      } else if (!strncmp(view_type->data.str, "graph", strlen("graph"))) {
        printf("Tu as choisis la graph view");
      } else {
        print_argument_error(view_type, INVALID_CHOICE_ARGUMENT);
      }
    } else {
      // linear view
      printf("Tu as choisis wola la linear view");
    }
  } else {

    print_help(parser);
  }
  free_instructions(instrs);
  free_parser(parser);
}
