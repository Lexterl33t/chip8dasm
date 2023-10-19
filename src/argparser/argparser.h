#pragma once

#include "../utils/utils.h"
#include "errors.h"

#define FOREACH_ARGUMENT(argument, code)                                       \
  while (argument) {                                                           \
    code;                                                                      \
    argument = argument->next;                                                 \
  }

#define TYPE_STR(t) TYPE[t]

extern const char *TYPE[];

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
  bool optional;

  union {
    int integer;
    bool boolean;
    char *str;
  } data;

} argument_t;

typedef struct {

  char **argv;
  int argc;
  char *project_name;
  char *description;
  char *help_bottom_text;
  argument_t *lhead;

} argument_parser_t;

argument_t *push_argument(argument_parser_t *ctx, argument_t *argument_in);
argument_parser_t *new_parser(char *project_name, char *description,
                              char *help_bottom_text, char **argv, int argc);
argument_t *add_argument(argument_parser_t *ctx, argument_type_t type,
                         char *command_name, char *help_text, bool optional);
void print_args(argument_parser_t *ctx);
void print_help(argument_parser_t *ctx);
argument_parser_t *parse_args(argument_parser_t *ctx);
argument_t *get_argument(argument_parser_t *ctx, char *command_name);
argument_t *set_argument(argument_t *argument, char *data);
void print_argument_error(argument_t *argument, PARSING_ERROR error);
