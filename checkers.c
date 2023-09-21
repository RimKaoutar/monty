#include "monty.h"

void is_readable(char *filename)
{
	if (access(filename, F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
