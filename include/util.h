#ifndef STAPLE_UTIL_H
#define STAPLE_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "bytebuffer.h"

char* read_ascii_file(const char* path);

uint8_t* read_binary_file(const char* path);
void write_binary_file(const char* path, ByteBuffer* bb);

uint16_t read16(uint8_t* buffer, uint32_t index);
uint32_t read32(uint8_t* buffer, uint32_t index);

#endif // STAPLE_UTIL_H