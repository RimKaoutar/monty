#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int linenum)
{
	unsigned int i = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		handle_error(ERR_ADD, NULL, linenum, NULL);

	i = tmp->n;
	j = tmp->next->n;
	tmp->next->n = i + j;
	*stack = tmp->next;
	free(tmp);
}
