#ifndef STAPLE_BYTEBUFFER_H
#define STAPLE_BYTEBUFFER_H

#include <stdlib.h>
#include <stdint.h>

struct _ByteBuffer {
	uint8_t* buffer;
	int ptr;
	int size;
};
typedef struct _ByteBuffer ByteBuffer;

ByteBuffer* byte_buffer_create(int size);
void byte_buffer_write8(ByteBuffer* bb, uint8_t data);
void byte_buffer_write16(ByteBuffer* bb, uint16_t data);
void byte_buffer_write32(ByteBuffer* bb, uint32_t data);
void byte_buffer_destroy(ByteBuffer* bb);

#endif // STAPLE_BYTEBUFFER_H