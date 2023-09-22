#include "monty.h"

/**
  * handle_error - Handles the printing of errors
  * @errno: Custom error code specifier.
  * @opcode: The operation code.
  * @line: The line on which the error occurred.
  * @linenum: The reserved error line buffer
  *
  * Return: Nothing
  */

void handle_error(int errnum, char *opcode, unsigned int line, char *linenum)
{
	if (errnum >= 100 && errnum < 200)
		handle_inv_malloc(errnum, opcode, line);
	else if (errnum >= 200 && errnum <= 210)
		handle_op_errors(errnum, line);
	else if (errnum >= 211 && errnum <= 220)
		handle_more_errors(errnum, line);
	else
		return;

	free_stack();

	if (linenum)
		free(linenum);

	exit(EXIT_FAILURE);
}

/**
  * handle_inv_malloc - Handles errors for malloc and bad instructions
  * @errnum: Custom error code specifier.
  * @opcode: The operation code.
  * @line: The line on which the error occurred.
  *
  * Return: Nothing
  */

void handle_inv_malloc(int errnum, char *opcode, unsigned int line)
{
	switch (errnum)
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
  * @errnum: Custom error code specifier.
  * @line: The line on which the error occurred.
  *
  * Return: Nothing
  */

void handle_op_errors(int errnum, unsigned int line)
{
	switch (errnum)
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
  * @errnum: Custom error code specifier.
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_more_errors(int errnum, unsigned int line)
{
	switch (errnum)
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
