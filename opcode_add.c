#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int u = 0, v = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_ADD, NULL, line_number, NULL);

	u = temp->n;
	v = temp->next->n;
	temp->next->n = u + v;
	*stack = temp->next;
	free(temp);
}
