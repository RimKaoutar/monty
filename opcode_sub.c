#include "monty.h"

/**
 * sub - func that subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int u = 0, v = 0, length = 0;
	stack_t *temp = *stack;

	length = count_stack(*stack);

	if (length < 2)
		handle_error(ERR_SUB, NULL, line_number, NULL);

	u = temp->n;
	v = temp->next->n;
	temp->next->n = v - u;
	*stack = temp->next;
	free(temp);
}
