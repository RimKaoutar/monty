#include "monty.h"

/**
 * mul - Performs multiplication of the top two elements of the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number of the operation
 * 
 * Description:
 * This function multiplies the top two elements of the stack.
 * It first counts the length of the stack and handles error
 * if less than 2 elements.
 * The integers of the top two nodes are stored in variables a and b.
 * It performs the multiplication operation b * a and stores
 * the result in the second node.
 * The top node is removed by updating the stack pointer, and
 * its memory is freed.
 * 
 * Return: None
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
