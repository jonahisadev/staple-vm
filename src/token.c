#include "../include/token.h"

void token_create(Token* tok, int type, int data, int line) {
	tok->type = type;
	tok->data = data;
	tok->line = line;
}

void token_destroy(Token* tok) {
	// free(tok);
}

void token_list_create(TokenList* list, int size) {
	list->data = (Token*) malloc(sizeof(Token) * size);
	list->ptr = 0;
	list->size = size;
}

void token_list_add(TokenList* list, Token tok) {
	if (list->ptr >= list->size) {
		list->size *= 2;
		list->data = (Token*) realloc(list->data, sizeof(Token) * list->size);
	}

	Token* t = &list->data[list->ptr++];
	token_create(t, tok.type, tok.data, tok.line);
}

Token* token_list_get(TokenList* list, int index) {
	return &list->data[index];
}

void token_list_destroy(TokenList* list) {
	for (int i = 0; i < list->ptr; i++) {
		token_destroy(&list->data[i]);
	}
	free(list->data);
}