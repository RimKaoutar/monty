#include "monty.h"

/**
 * divide - Divides the second top element by the top element of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		handle_error(ERR_DIV, NULL, line_number, NULL);

	i = tmp->n;

	if (i == 0)
		handle_error(ERR_ZERO_DIV, NULL, line_number, NULL);

	j = tmp->next->n;
	tmp->next->n = j / i;
	*stack = tmp->next;
	free(tmp);
}
