#pragma once

#include <stdint.h>
#include <stdio.h>

uint16_t *parse_binary_rom(int fd, uint32_t *num_bytes);
