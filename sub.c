#include "monty.h"

/**
 * sub - Subtracts the top two elements of the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number
 *
 * Description:
 * This function subtracts the top two elements of the stack.
 * It first counts the stack length and checks for min length.
 * Two variables a and b hold the values of top two elements.
 * The subtraction b - a is performed and stored in next node.
 * The top node is freed after updating the stack pointer.
 * This implements subtraction on the stack without popping.
 *
 * Return: None
 */
void sub(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = *stack;
	unsigned int a = 0, b = 0, length = 0;

	length = count_stack(*stack);

	if (length < 2)
		error_manager(ERR_SUB, NULL, linenum, NULL);

	a = tmp->n;
	b = tmp->next->n;
	tmp->next->n = a - b;
	*stack = tmp->next;
	free(tmp);
}
