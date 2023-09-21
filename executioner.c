#include "monty.h"

/**
 * splitter - this will take the line buff, and splits it into tokens,
 * each two tokens will be given to exec (below) to execute on it, exec will
 * be the one to check for the edge cases (n not an int, null , etc..)
 * @line_buff: the line buffer
 * @stack: the stack
*/
void splitter(char* line_buffer, stack_t **stack)
{
	char *token = NULL;
	unsigned int line_nbr = 0;
	int opcode_arg = 0;

	if (!line_buffer)
	{
		perror("error: splitter: token is null");
		free(line_buffer);
		exit(EXIT_FAILURE);
	}
	token = strtok(line_buffer, " \t\n");
	while (token)
	{
		line_nbr++;
		opcode_arg = atoi(strtok(NULL, " \n\t"));
		if (!opcode_arg)
		{
			fprintf(stderr, "L%d: usage: push integer");
			free(line_buffer);
			exit(EXIT_FAILURE);
		}
		exec(token, opcode_arg, line_nbr);
		token = strtok(NULL, " \t\n");
	}

}

/**
 * exec - this funct will take the opcode and see if it exists in the instructions stack,
 * if not print out the error
 * @opdoce: the opcode, it will be the return of the strtok on the linebuffer
 * @line_number: the line number
 * Return: the return will be the pointer to the function that
 * does the opcode, or NULL
*/
void (*exec(char *op_code, char *n, unsigned int line_number))
(stack_t **, unsigned int)
{
	instruction_t instruction[] = {{"pall", pall}, {"push", push}, {NULL, NULL}};

	instruction_t *curr = instruction;
	while (curr->opcode)
	{
		if (strcmp(op_code, curr->opcode) == 0)
		{
			return (curr->f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", line_number, op_code);
	return (NULL);
}
