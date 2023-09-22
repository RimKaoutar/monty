#include "monty.h"
/**
 * pall - Prints all the values in the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number (unused)
 * 
 * Description:
 * This function prints all the elements of the stack.
 * It takes the head node and iterates through the stack:
 * Checks for empty stack
 * Prints the data of current node
 * Moves to the next node
 * The line number parameter is declared as unused to avoid
 * compiler warnings.
 * This provides a way to print the entire stack contents.
 * 
 * Return: None
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
