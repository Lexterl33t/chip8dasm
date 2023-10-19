#include <stdio.h>
#include <string.h>

#include "../logging/logger.h"
#include "argparser.h"
#include "errors.h"

const char *TYPE[] = {"Integer", "String", "Boolean"};

/*
 * Parser constructor
 * TODO: Documentation new_parser
 */

argument_parser_t *new_parser(char *project_name, char *description,
                              char *help_bottom_text, char **argv, int argc) {

  if (!description || !help_bottom_text) {
    critical_error(
        "(argparser::new) : description and help_bottom_text can't be empty");
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
  argument->optional = true;
  argument->is_set = true;

  parser->project_name = project_name;
  parser->description = description;
  parser->help_bottom_text = help_bottom_text;
  parser->lhead = argument;
  parser->argv = argv;
  parser->argc = argc;

  return parser;
}

argument_t *add_argument(argument_parser_t *ctx, argument_type_t arg_type,
                         char *command_name, char *help_text, bool optional) {

  if (!ctx || !command_name || !help_text) {
    // TODO: create method to free linked list
    critical_error("(argparser::add_argument) : ctx, command_name, help_text, "
                   "can't be NULL");
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
  new_argument->is_set = false;

  new_argument = push_argument(ctx, new_argument);

  return new_argument;
}

argument_t *push_argument(argument_parser_t *ctx, argument_t *argument_in) {

  if (!ctx || !argument_in) {
    // TODO: Create method to free linked list
    critical_error(
        "(argument::push_argument) : head, argument_in can't be NULL");
  }

  argument_in->next = ctx->lhead;
  ctx->lhead = argument_in;

  return argument_in;
}

void print_args(argument_parser_t *ctx) {

  if (!ctx) {
    critical_error("(argparser::print_args) : Ctx can't be null");
  }

  argument_t *it = ctx->lhead;

  FOREACH_ARGUMENT(it, {
    if (it->command_name)
      switch (it->type) {
      case INT:
        printf("Command name: %s, type: %d, value: %d\n", it->command_name,
               it->type, it->data.integer);
        break;
      case STRING:
        printf("Command name: %s, type: %d, value: %s\n", it->command_name,
               it->type, it->data.str);
        break;
      case BOOL:
        printf("Command name: %s, type: %d, value: %d\n", it->command_name,
               it->type, it->data.boolean);
        break;
      }
  });
}

void print_help(argument_parser_t *ctx) {

  if (!ctx) {
    critical_error("(argparser::print_help) : Ctx can't be null");
  }

  argument_t *it = ctx->lhead;

  printf("[ %s ]\n", ctx->project_name);
  FOREACH_ARGUMENT(it, {
    if (it->command_name)
      printf("%s : %s : %s\n", it->command_name, it->help, TYPE_STR(it->type));
  })

  exit(0);
}

argument_t *get_argument(argument_parser_t *ctx, char *command_name) {

  argument_t *it = ctx->lhead;

  FOREACH_ARGUMENT(it, {
    if (it->command_name &&
        !strncmp(it->command_name, command_name, strlen(it->command_name)))
      return it;
  })

  return NULL;
}

void print_argument_error(argument_t *argument, PARSING_ERROR error) {
  switch (error) {
  case INVALID_ARGUMENT_TYPE:
    fprintf(stderr, "Invalid argument type for %s the type must be %s\n",
            argument->command_name, TYPE_STR(argument->type));
    exit(0);
  case EMPTY_COMMAND_ARGUMENT:
    fprintf(stderr, "Command %s must %s argument\n", argument->command_name,
            TYPE_STR(argument->type));
    exit(0);
  case INVALID_ARGUMENT:
    fprintf(stderr, "Unknown command");
    exit(0);
  case REQUIRED_COMMAND_NOT_EXIST:
    fprintf(stderr, "Command %s is required\n", argument->command_name);
    exit(0);
  }
}

argument_t *set_argument(argument_t *argument, char *data) {

  if (!argument || !data) {
    critical_error(
        "(argparser::set_argument) : argument and data can't be NULL");
  }

  switch (argument->type) {
  case INT:
    if (is_integer(data)) {
      argument->data.integer = atoi(data);
    } else {
      print_argument_error(argument, INVALID_ARGUMENT_TYPE);
    }
    break;
  case STRING:
    argument->data.str = data;
    break;
  case BOOL:
    if (!strncmp(data, "true", 4))
      argument->data.boolean = true;
    else if (!strncmp(data, "false", 5))
      argument->data.boolean = false;
    else
      print_argument_error(argument, INVALID_ARGUMENT_TYPE);
    break;
  }

  argument->is_set = true;
  return argument;
}

argument_parser_t *parse_args(argument_parser_t *ctx) {

  for (int i = 1; i < ctx->argc; ++i) {
    char *str = ctx->argv[i];

    if (!(strncmp("--help", str, 7))) {
      print_help(ctx);
    }

    argument_t *search_argument = get_argument(ctx, str);

    if (search_argument) {
      if ((i + 1) < ctx->argc)
        set_argument(search_argument, ctx->argv[++i]);
      else
        print_argument_error(search_argument, EMPTY_COMMAND_ARGUMENT);
    } else {
      print_argument_error(search_argument, INVALID_ARGUMENT);
    }
  }

  argument_t *it = ctx->lhead;

  // TODO: Iterate argument linked list and check if !optional argument are set
  // or no
  FOREACH_ARGUMENT(it, {
    if (it->command_name && !it->optional) {
      if (!it->is_set) {
        print_argument_error(it, REQUIRED_COMMAND_NOT_EXIST);
      }
    }
  })
  return ctx;
}
