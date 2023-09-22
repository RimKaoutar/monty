#include "monty.h"

/**
 * divide - Divides the top two elements of a stack and replaces
 * them with the result
 * @stack: Double pointer to the stack
 * @line_number: Line number of error origin if any
 * 
 * Description:
 * This function divides the data (n) of the second node by the
 * top node of the stack.
 * It checks for invalid cases like length < 2, zero divisor.
 * If valid, it performs the division, stores result in second
 * node, removes top node and frees its memory.
 * 
 * Return: None
 */
void divide(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		error_manager(ERR_DIV, NULL, line_number, NULL);

	i = tmp->n;

	if (i == 0)
		error_manager(ERR_ZERO_DIV, NULL, line_number, NULL);

	j = tmp->next->n;
	tmp->next->n = j / i;
	*stack = tmp->next;
	free(tmp);
}
