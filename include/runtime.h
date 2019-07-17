#ifndef STAPLE_RUNTIME_H
#define STAPLE_RUNTIME_H

#include <stdbool.h>

#include "bytecode.h"
#include "util.h"

#define STACK_SIZE 1024

enum _RuntimeStatus {
	RUNTIME_SUCCESS,
	RUNTIME_ERROR,
};
typedef enum _RuntimeStatus RuntimeStatus;

struct _Runtime {
	uint8_t* code;
	RuntimeStatus status;
	uint8_t stack[STACK_SIZE];
	uint32_t sp;
	uint32_t ip;
	uint8_t exit;
	bool running;
};
typedef struct _Runtime Runtime;

void runtime_start(Runtime* runtime);

// Stack functions
void push8(Runtime* r, uint8_t data);
void push16(Runtime* r, uint16_t data);
void push32(Runtime* r, uint32_t data);
uint8_t pop8(Runtime* r);
uint16_t pop16(Runtime* r);
uint32_t pop32(Runtime* r);

#endif // STAPLE_RUNTIME_H