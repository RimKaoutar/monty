#include "monty.h"

stack_t *head = NULL;

/**
  * main - Entry point for the Monty Interpreter
  * @argc: Number of arguments passed into the program.
  * @argv: Vector containing the arguments passed.
  *
  * Return: Always 0.
  */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *filename = NULL, *opcode = NULL, *n = NULL, *linenum = NULL;
	size_t len = 0;
	int status = 0, cmd = 0;
	unsigned int linenum = 0;

	filename = argv[1];
	check_args_num(argc);
	file = open_file(filename);

	while ((cmd = getline(&linenum, &len, file)) != -1)
	{
		linenum++;
		opcode = strtok(linenum, " \t\n");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;

			n = strtok(NULL, " \t\n");
			status = handle_execution(opcode, n, linenum, status);

			if (status >= 100 && status < 300)
			{
				fclose(file);
				handle_error(status, opcode, linenum, linenum);
			}
		}

	}

	free_stack();
	free(linenum);
	fclose(file);
	return (0);
}
