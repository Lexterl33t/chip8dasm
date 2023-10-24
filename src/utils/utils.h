#pragma once

#define TO_LITTLE_ENDIAN_16b(x)                                                \
  ((__uint16_t)((((x) >> 8) & 0xff) | (((x)&0xff) << 8)))

typedef enum { false, true } bool;

bool is_integer(char *str);

char to_lower_char(char c);

bool is_alpha(char c);

void to_lower(char *str);
