#include "../include/util.h"

char* read_ascii_file(const char* path) {
	// Create a file
	FILE* file = fopen(path, "r");
	if (!file) {
		printf("Could not open file '%s'\n", path);
		return NULL;
	}

	// Get the file size
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Read file
	char* buf = (char*) malloc(sizeof(char) * (size + 1));
	if (!buf) {
		printf("Could not allocate memory for file!\n");
		return NULL;
	}
	fread(buf, 1, size, file);
	buf[size] = '\0';
	fclose(file);

	// Return contents
	return buf;
}

void write_binary_file(const char* path, ByteBuffer* bb) {
	FILE* file = fopen(path, "wb");
	if (!file) {
		printf("Could not write to file '%s'\n", path);
		return;
	}

	fwrite(bb->buffer, 1, bb->ptr, file);
	fclose(file);
}