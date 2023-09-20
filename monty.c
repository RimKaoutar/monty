#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *filename = NULL, line = NULL;
	int cmd = 0;
	size_t len = 0;

	filename = argv[1];

	/* must check if the file is readable */
	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while( (cmd = getline(&line, len, file)) != -1)
	{
		/* handles this later */
	}
	
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);

	
}
