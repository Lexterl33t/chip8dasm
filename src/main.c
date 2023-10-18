
#include <stdio.h>

#include "argparser/argparser.h"

int main(int argc, char **argv) {
  
  argument_parser_t *parser = new_parser("My project", "Hello, world", "kaka", argv, argc);
  

  add_argument(parser, INT, "Hello, world", "kaka", true);
  add_argument(parser, STRING, "Issoufre", "lalalal", true);


  print_help(parser);
  
   
      
}

