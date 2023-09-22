#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int linenum)
{
	unsigned int a = 0, b = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		handle_error(ERR_MUL, NULL, linenum, NULL);

	a = tmp->n;
	b = tmp->next->n;
	tmp->next->n = b * a;
	*stack = tmp->next;
	free(tmp);
}
