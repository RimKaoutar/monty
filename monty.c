#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * 
 * Description:
 * Opens the Monty bytecodes file and processes each line:
 * Checks arguments
 * Opens file
 * Repeatedly reads each line
 * Skips comments
 * Tokens opcode and parameter
 * Handles execution
 * Handles any errors
 * After processing all lines:
 * Frees stack memory
 * Closes file
 * 
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	size_t len = 0;
	unsigned int linenum = 0;
	int cmd = 0, status = 0;
	char *filename = NULL, *opcode = NULL, *n = NULL, *rline = NULL;

	filename = argv[1];
	check_args_num(argc);
	file = open_file(filename);

	while ((cmd = getline(&rline, &len, file)) != -1)
	{
		linenum++;
		opcode = strtok(rline, " \t\n");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;

			n = strtok(NULL, " \t\n");
			status = executionner(opcode, n, linenum, status);

			if (status >= 100 && status < 300)
			{
				fclose(file);
				error_manager(status, opcode, linenum, rline);
			}
		}

	}

	_free();
	free(rline);
	fclose(file);
	return (0);
}