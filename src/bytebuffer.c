#include "../include/bytebuffer.h"

ByteBuffer* byte_buffer_create(int size) {
	ByteBuffer* bb = (ByteBuffer*) malloc(sizeof(ByteBuffer));
	bb->buffer = (uint8_t*) malloc(sizeof(uint8_t) * size);
	bb->ptr = 0;
	bb->size = size;
	return bb;
}

void byte_buffer_write8(ByteBuffer* bb, uint8_t data) {
	if (bb->ptr >= bb->size) {
		bb->size *= 2;
		bb->buffer = (uint8_t*) realloc(bb->buffer, sizeof(uint8_t) * bb->size);
	}

	bb->buffer[bb->ptr++] = data;
}

void byte_buffer_write16(ByteBuffer* bb, uint16_t data) {
	byte_buffer_write8(bb, (data & 0xFF00) >> 8);
	byte_buffer_write8(bb, (data & 0x00FF));
}

void byte_buffer_write32(ByteBuffer* bb, uint32_t data) {
	byte_buffer_write8(bb, (data & 0xFF000000) >> 24);
	byte_buffer_write8(bb, (data & 0x00FF0000) >> 16);
	byte_buffer_write8(bb, (data & 0x0000FF00) >> 8);
	byte_buffer_write8(bb, (data & 0x000000FF));
}

void byte_buffer_destroy(ByteBuffer* bb) {
	free(bb->buffer);
	free(bb);
}