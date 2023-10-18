#include <stdio.h>

#include "argparser.h"
#include "../logging/logger.h"


const char *TYPE[] = {
  "Integer",
  "String",
  "Boolean"
};

/*
* Parser constructor
* TODO: Documentation new_parser 
*/

argument_parser_t *new_parser(char *project_name, char *description, char *help_bottom_text, char **argv, int argc) {

  if (!description || !help_bottom_text) {
    critical_error("(argparser::new) : description and help_bottom_text can't be empty");  
  }

  argument_parser_t *parser = malloc(sizeof(argument_parser_t));

  if (!parser) {
    critical_error("(argparser::new) : Error allocation argument_parser_t");
  }

  argument_t *argument = malloc(sizeof(argument_t));


  if (!argument) {
    free(parser);
    critical_error("(argparser::new) : Error allocation argument_t");
  }

  argument->command_name = NULL;
  argument->help = NULL;
  argument->next = NULL;

  parser->project_name = project_name;
  parser->description = description;
  parser->help_bottom_text = help_bottom_text;
  parser->lhead = argument;


  return parser;
}


argument_t *add_argument(argument_parser_t *ctx, argument_type_t arg_type, char *command_name, char *help_text, bool optional) { 
  
  if (!ctx || !command_name || !help_text) { 
    // TODO: create method to free linked list
    critical_error("(argparser::add_argument) : ctx, command_name, help_text, arg_type can't be empty");
  }
  
  
  argument_t *new_argument = malloc(sizeof(argument_t));

  if (!new_argument) {
    free(ctx);

    critical_error("(argparser::add_argument) : Error allocation argument_t");
  }

  new_argument->command_name = command_name;
  new_argument->help = help_text;
  new_argument->type = arg_type;
  new_argument->optional = optional;

  new_argument = push_argument(ctx, new_argument);

  return new_argument;
   
}

argument_t *push_argument(argument_parser_t *ctx, argument_t *argument_in) {
  
  if (!ctx || !argument_in) {
    // TODO: Create method to free linked list
    critical_error("(argument::push_argument) : head, argument_in can't be NULL");
  } 

  argument_in->next = ctx->lhead;
  ctx->lhead = argument_in;


  return argument_in;
    
}

void print_args(argument_parser_t *ctx) {
  
  argument_t *it = ctx->lhead;

  FOREACH_ARGUMENT(it, {
    if (it->command_name)
      printf("Command name: %s, type: %d, value: %d\n", it->command_name, it->type, it->data.integer);
  });
}


void print_help(argument_parser_t *ctx) {
  
  argument_t *it = ctx->lhead;
  
  printf("[ %s ]\n", ctx->project_name);
  FOREACH_ARGUMENT(it, {
    if (it->command_name)
      printf("%s : %s : %s\n", it->command_name, it->help, TYPE_STR(it->type));
  })
}


argument_parser_t *parse_args(argument_parser_t *ctx) {
   
}
