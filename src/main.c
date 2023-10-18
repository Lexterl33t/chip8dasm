
#include <stdio.h>

#include "argparser/argparser.h"

int main(int argc, char **argv) {
  
  argument_parser_t *parser = new_parser("Hello, world", "kaka");
  

  add_argument(parser, INT, "Hello, world", "kaka");
  add_argument(parser, STRING, "Issoufre", "lalalal");

  print_args(parser);
}

