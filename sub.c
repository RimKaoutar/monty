#include "monty.h"

/**
 * sub - func that subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: The head of the stack
 * @linenum: Line number of the command in the bytecode file
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_SUB, NULL, linenum, NULL);

	a = tmp->n;
	b = tmp->next->n;
	tmp->next->n = a - b;
	*stack = tmp->next;
	free(tmp);
}
