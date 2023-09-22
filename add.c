#include "monty.h"

/**
 * add - Adds the top two elements of a stack_t stack and replaces
 * them with their sum.
 * @stack: Double pointer to the top node of the stack
 * @linenum: Line number of error origin if any
 * 
 * Description:
 * This function adds the data element (n) of the top two nodes
 * of the stack. It updates the data of the second node with the
 * sum and removes the top node, effectively performing an "add"
 * operation on the stack.
 * It first checks if there are less than two elements to perform
 * the operation. If so, it calls error_manager().
 * It then saves the data of the top two nodes, performs the addition
 * and stores the result in the second node. The top node is freed
 * after removing it from the stack.
 * 
 * Return: Nothing
 */
void add(stack_t **stack, unsigned int linenum)
{
	unsigned int i = 0, j = 0, len = 0;
	stack_t *tmp = *stack;

	len = count_stack(*stack);

	if (len < 2)
		error_manager(ERR_ADD, NULL, linenum, NULL);

	i = tmp->n;
	j = tmp->next->n;
	tmp->next->n = i + j;
	*stack = tmp->next;
	free(tmp);
}
