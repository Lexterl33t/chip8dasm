#pragma once

#include <stdlib.h>
#include <stdio.h>

static inline void critical_error(char *str) {
  fprintf(stderr, "ERROR: %s\n", str);
  exit(0);
}
