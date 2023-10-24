#pragma once

#include "../utils/utils.h"
#include <stdint.h>

typedef struct {

  char *opcode_str;
  int16_t nibble;
  bool is_duplicate;
} instruction_t;
