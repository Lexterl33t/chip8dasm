
#include <stdio.h>

#include "argparser/argparser.h"

int main(int argc, char **argv) {

  argument_parser_t *parser =
      new_parser("My project", "Hello, world", "kaka", argv, argc);

  add_argument(parser, INT, "--test", "this is test int command", true);
  add_argument(parser, STRING, "Issoufre", "lalalal", true);

  parse_args(parser);

  print_args(parser);
}
