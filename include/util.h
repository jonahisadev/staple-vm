#ifndef STAPLE_UTIL_H
#define STAPLE_UTIL_H

#include <stdio.h>
#include <stdlib.h>

#include "bytebuffer.h"

char* read_ascii_file(const char* path);
void write_binary_file(const char* path, ByteBuffer* bb);

#endif // STAPLE_UTIL_H