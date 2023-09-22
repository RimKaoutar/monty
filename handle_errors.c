#include "monty.h"

/**
  * handle_error - Handles the printing of errors
  * @errno: Custom error code specifier.
  * @opcode: The operation code.
  * @line: The line on which the error occurred.
  * @line_read: The reserved error line buffer
  *
  * Return: Nothing
  */

void handle_error(int errno, char *opcode, unsigned int line, char *line_read)
{
	if (errno >= 100 && errno < 200)
		handle_inv_malloc(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_op_errors(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_more_errors(errno, line);
	else
		return;

	free_stack();

	if (line_read)
		free(line_read);

	exit(EXIT_FAILURE);
}

/**
  * handle_inv_malloc - Handles errors for malloc and bad instructions
  * @errno: Custom error code specifier.
  * @opcode: The operation code.
  * @line: The line on which the error occurred.
  *
  * Return: Nothing
  */

void handle_inv_malloc(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case ERR_INVALID:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_MALLOC:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
  * handle_op_errors - Handles errors for opcode operations.
  * @errno: Custom error code specifier.
  * @line: The line on which the error occurred.
  *
  * Return: Nothing
  */

void handle_op_errors(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_USAGE:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case ERR_PUSH:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case ERR_PINT:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case ERR_POP:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case ERR_SWAP:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ERR_ADD:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case ERR_SUB:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case ERR_DIV:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ERR_ZERO_DIV:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case ERR_MUL:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case ERR_MOD:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}

/**
  * handle_more_errors - Handles errors for pchar.
  * @errno: Custom error code specifier.
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_more_errors(int errno, unsigned int line)
{
	switch (errno)
	{
		case ERR_PCHAR_F:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case ERR_PCHAR_E:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
}
