#include "../include/parser.h"

ParserStatus parser_start(TokenList* list, const char* source) {
	char lex[256];
	int lexi = 0;
	int i = 0;
	int line = 1;

	while (1) {
		// memset(lex, 0, 256);

		while (source[i] != ' ' && source[i] != '\n' && source[i] != '\0') {
			lex[lexi++] = source[i++];
		}
		lex[lexi] = '\0';

		// TODO: care about empty lines
		// TODO: care about tabs

		Token token;

		// This is a numerical constant
		if (lex[0] == '#') {
			int num = parser_get_number(lex);
			// printf("NUMBER: %d\n", num);
			token_create(&token, NUMBER, num, line);
			token_list_add(list, token);
		}

		// Must be an instruction
		else {
			int inst = parser_get_inst(lex);
			if (inst >= 0) {
				// printf("INST: %s\n", lex);
				token_create(&token, INST, inst, line);
				token_list_add(list, token);
			} else {
				printf("Syntax error: no such instruction '%s'\n", lex);
				return PARSER_SYNTAX_ERROR;
			}
		}

		// New line
		if (source[i] == '\n') {
			line++;
		}

		// End of file
		else if (source[i] == '\0') {
			break;
		}

		lexi = 0;
		i++;
	}

	return PARSER_SUCCESS;
}

uint32_t parser_get_number(const char* buf) {
	long num = atoi(&buf[1]);
	return (num <= UINT32_MAX) ? num : 0;
}

TokenInst parser_get_inst(const char* buf) {
	if (strcmp(buf, "push") == 0)
		return PUSH;
	if (strcmp(buf, "add") == 0)
		return ADD;
	if (strcmp(buf, "hlt") == 0)
		return HLT;
	return (TokenInst)-1;
}