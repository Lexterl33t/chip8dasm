#include "utils.h"
#include <ctype.h>

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

bool is_alpha(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return true;

  return false;
}

char to_lower_char(char c) {

  if (is_alpha(c)) {
    if (c >= 'A' && c <= 'Z')
      return c + 32;
  }

  return c;
}

void to_lower(char *str) {

  char *tmp = str;

  while (*tmp) {
    *tmp = to_lower_char(*tmp);
    tmp++;
  }
}
