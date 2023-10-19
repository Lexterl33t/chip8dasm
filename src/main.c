
#include <stdio.h>

#include "argparser/argparser.h"

int main(int argc, char **argv) {

  argument_parser_t *parser =
      new_parser("My project", "Hello, world", "kaka", argv, argc);

  add_argument(parser, INT, "--test", "this is test int command", true);
  add_argument(parser, STRING, "Issoufre", "lalalal", true);
  add_argument(parser, BOOL, "--required-command",
               "ceci est la commande requit", false);

  parse_args(parser);

  argument_t *require_command = get_argument(parser, "--required-command");

  printf("Value: %d", require_command->data.boolean);

  print_args(parser);
  free_parser(parser);
}
