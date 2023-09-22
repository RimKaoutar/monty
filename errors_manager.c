#include "monty.h"

/**
 * handle_error - Handles program errors
 * @errnum: Error number code
 * @opcode: Causing operation if any
 * @line: Line number of error
 * @linenum: Saved line number string if any
 * 
 * Description:
 * This function handles different types of errors based on the
 * error number code range.
 * It will call the appropriate error handling function:
 * handle_inv_malloc for invalid memory errors
 * handle_op_errors for operation errors
 * handle_more_errors for other errors
 * It then frees all resources by calling free_stack().
 * If a line number string was passed, it is freed as well.
 * Finally, the program exits with failure status.
 * 
 * Return: None
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
 * handle_inv_malloc - Handles errors for invalid memory allocation
 * @errnum: Specific error number code
 * @opcode: Causing operation if any
 * @line: Line number of error
 * 
 * Description:
 * This function handles printing appropriate error messages
 * for invalid memory allocation errors.
 * It uses a switch statement to check the error number:
 * Case ERR_INVALID:
 *  Prints unknown instruction error  
 * Case ERR_MALLOC:
 *  Prints generic malloc failure error
 * Default:
 *  Takes no action
 * The line number and failing operation are included in
 * error messages where applicable.
 * This allows customized error handling for different
 * invalid memory conditions.
 * 
 * Return: None
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
 * handle_op_errors - Handles errors for invalid operations
 * @errnum: Specific error code
 * @line: Line number of error
 * 
 * Description:
 * Prints customized error messages for operation errors using
 * a switch statement.
 * Errors handled:
 * ERR_USAGE
 * ERR_PUSH
 * ERR_PINT
 * ERR_POP
 * ERR_SWAP
 * ERR_ADD
 * ERR_SUB
 * ERR_DIV
 * ERR_ZERO_DIV
 * ERR_MUL
 * ERR_MOD
 * Line number is included in messages.
 * Default case takes no action.
 * This provides detailed error contexts to operations.
 * 
 * Return: None
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
 * handle_more_errors - Handles additional error cases
 * @errnum: Specific error code
 * @line: Line number of error
 * 
 * Description:
 * Using a switch statement, this function handles printing messages
 * for any miscellaneous error codes not covered elsewhere.
 * Errors currently handled:
 * ERR_PCHAR_F: Value out of range for pchar
 * ERR_PCHAR_E: Empty stack for pchar
 * Default case takes no action.
 * The line number is included in error messages.
 * This provides customized outputs for any unique error conditions.
 * 
 * Return: None
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
