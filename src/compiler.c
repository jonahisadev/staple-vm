#include "../include/compiler.h"

void compiler_start(Compiler* c) {
	c->bytecode = byte_buffer_create(1);

	for (int i = 0; i < c->tokens->ptr; i++) {
		Token* t = token_list_get(c->tokens, i);

		if (t->type == INST) {
			switch (t->data) {
				
				// PUSH
				case PUSH: {
					// PUSH #N
					if (token_list_get(c->tokens, i + 1)->type == NUMBER) {
						byte_buffer_write8(c->bytecode, PUSH_CONST);
						byte_buffer_write32(c->bytecode, token_list_get(c->tokens, i + 1)->data);
						i++;
					} else {
						printf("Bad PUSH inst\n");
						c->status = COMPILER_ERROR;
						return;
					}
					break;
				}

				// ADD
				case ADD: {
					byte_buffer_write8(c->bytecode, ADD_STACK);
					break;
				}

				// SUB
				case SUB: {
					byte_buffer_write8(c->bytecode, SUB_STACK);
					break;
				}

				// MUL
				case MUL: {
					byte_buffer_write8(c->bytecode, MUL_STACK);
					break;
				}

				// HLT
				case HLT: {
					byte_buffer_write8(c->bytecode, HLT_OP);
					break;
				}

				default: {
					printf("Unknown instruction token\n");
					c->status = COMPILER_ERROR;
					return;
				}

			}
		}
	}

	c->status = COMPILER_SUCCESS;
}