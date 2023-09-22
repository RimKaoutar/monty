#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *		 of the stack by the top element of the stack
 * @stack: The head of the stack
 * @linenum: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int linenum)
{
	unsigned int i = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		handle_error(ERR_MOD, NULL, linenum, NULL);

	i = tmp->n;

	if (i == 0)
		handle_error(ERR_ZERO_DIV, NULL, linenum, NULL);

	j = tmp->next->n;
	tmp->next->n = j % i;
	*stack = tmp->next;
	free(tmp);
}
