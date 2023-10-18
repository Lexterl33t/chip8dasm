#include "utils.h"

bool is_integer(char *str) {

  char *tmp = str;

  while (*tmp) {
    if (*tmp < '0' || *tmp > '9')
      if (tmp - str != 0 || *tmp != '-')
        return false;

    tmp++;
  }

  return true;
}
