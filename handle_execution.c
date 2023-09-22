#include "monty.h"

/**
 * executionner - Executes opcode functions with parameters
 * @op_code: Opcode string read from file
 * @n: Parameter to pass for push opcode
 * @line: Line number of opcode
 * @meth: Stack/queue method
 * 
 * Description:
 * First checks if opcode specifies stack/queue method and returns.
 * Gets function pointer for opcode and checks for validity.
 * For push, validates parameter and calls appropriate push function.
 * For other opcodes, directly calls function with line number.
 * Handles queue method by calling push_queue instead of push.
 * Returns ERR_INVALID if opcode not found, method otherwise.
 * This function centralizes execution logic and parameter handling.
 * 
 * Return: ERR_INVALID or method
*/

int executionner(char *op_code, char *n, unsigned int line, int meth)
{
	int status_op = 0;
	void (*opcode_function)(stack_t **, unsigned int);

	if (strcmp(op_code, "stack") == 0)
		return (METH_STACK);
	else if (strcmp(op_code, "queue") == 0)
		return (METH_QUEUE);

	opcode_function = get_opcode(op_code);
	if (opcode_function)
	{
		if (strcmp(op_code, "push") == 0)
		{
			status_op = check_push_n(n);
			if (status_op == ERR_PUSH)
				return (ERR_PUSH);

			if (meth != 0 && meth == METH_QUEUE)
				opcode_function = get_opcode("push_queue");

			opcode_function(&head, atoi(n));
		}
		else
			opcode_function(&head, line);

		return (meth);
	}

	return (ERR_INVALID);
}
