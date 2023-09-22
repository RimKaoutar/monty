#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: The head of the stack
 * @linenum: Line number of the command in the bytecode filetecode file
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *current = NULL;
	(void) linenum;

	if (*stack)
	{
		current = *stack;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
