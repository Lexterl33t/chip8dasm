#pragma once

#include "errors.h"

#define FOREACH_ARGUMENT(argument, code) \
  while (argument) { \
    code; \
    argument = argument->next; \
  } 
 
typedef enum {
  INT,
  STRING,
  BOOL,
} argument_type_t;


typedef struct argument_s {
  
  char *command_name;
  char *help;
  argument_type_t type;
  struct argument_s *next;
   
} argument_t;


typedef struct {

  char *description;
  char *help_bottom_text;
  argument_t *lhead;
   
} argument_parser_t;




argument_t *push_argument(argument_parser_t *ctx, argument_t *argument_in);
argument_parser_t *new_parser(char *description, char *help_bottom_text);
argument_t *add_argument(argument_parser_t *ctx, argument_type_t type, char *command_name, char *help_text);
void print_args(argument_parser_t *ctx);

