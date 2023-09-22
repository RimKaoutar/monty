#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *		 of the stack by the top element of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int u = 0, v = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_MOD, NULL, line_number, NULL);

	u = temp->n;

	if (u == 0)
		handle_error(ERR_ZERO_DIV, NULL, line_number, NULL);

	v = temp->next->n;
	temp->next->n = v % u;
	*stack = temp->next;
	free(temp);
}
