#include "monty.h"

/**
  * handle_execution - Manages the operations to be executed by the interpreter
  * @op_code: The operation code to execute.
  * @n: The data that comes with the instruction.
  * @line: Line number of the command in the bytecode file
  * @meth: Indicates if the push operation should be stack or queue
  *
  * Return: 0 if the operation was successful or errcode if its invalid.
  */

int handle_execution(char *op_code, char *n, unsigned int line, int meth)
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
