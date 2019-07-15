#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/util.h"
#include "../include/parser.h"
#include "../include/compiler.h"
#include "../include/token.h"

// staple compile file.stvm

int main(int argc, char** argv) {
	if (argc <3) {
		printf("Too few arguments\n");
		return 1;
	}

	if (strcmp(argv[1], "compile") == 0) {
		char* source = read_ascii_file(argv[2]);
		TokenList tokens;
		token_list_create(&tokens, 1);

		ParserStatus pstat = parser_start(&tokens, source);
		if (pstat != PARSER_SUCCESS)
			return 1;
		
		Compiler comp;
		comp.tokens = &tokens;
		compiler_start(&comp);
		if (comp.status != COMPILER_SUCCESS)
			return 1;

		write_binary_file("out.stbc", comp.bytecode);

		byte_buffer_destroy(comp.bytecode);
		token_list_destroy(&tokens);
		free(source);
	}

	return 0;
}