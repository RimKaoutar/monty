#include "monty.h"

/**
 * mod - Performs modulo operation on the top two elements of stack
 * @stack: Double pointer to stack
 * @linenum: Line number of operation
 * 
 * Description:
 * This function performs modulo (%) operation on the top two
 * elements of the stack.
 * It first counts stack length and handles error if less than 2.
 * The integer values of top two nodes are stored in i and j.
 * It checks for zero modulo and handles error.
 * The modulo operation j % i is performed and result stored
 * in the second node.
 * Top node is removed, its memory freed and stack updated.
 * 
 * Return: None
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
