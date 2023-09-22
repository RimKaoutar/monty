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
	FILE *monty_file = NULL;
	size_t cmd_len = 0;
	unsigned int line_number = 0;
	int command = 0, status = 0;
	char *filename = NULL, *opcode = NULL, *data = NULL, *line_read = NULL;

	filename = argv[1];
	check_args_num(argc);
	monty_file = open_file(filename);

	while ((command = getline(&line_read, &cmd_len, monty_file)) != -1)
	{
		line_number++;
		opcode = strtok(line_read, " \t\n");
		if (opcode)
		{
			if (opcode[0] == '#')
				continue;

			data = strtok(NULL, " \t\n");
			status = handle_execution(opcode, data, line_number, status);

			if (status >= 100 && status < 300)
			{
				fclose(monty_file);
				handle_error(status, opcode, line_number, line_read);
			}
		}

	}

	free_stack();
	free(line_read);
	fclose(monty_file);
	return (0);
}
