#include "monty.h"

/**
 * pstr - Prints the string represented by the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number (unused)
 * 
 * Description:
 * This function prints the string represented by the stack contents.
 * It takes the head node and iterates through the stack:
 * Prints character if within ASCII range 0-127
 * Moves to next node
 * Stops on out of range character
 * The line number parameter is unused.
 * A newline is printed at the end.
 * This allows printing string values stored in the stack.
 * 
 * Return: None
*/
void pstr(stack_t **stack, unsigned int linenum)
{
	stack_t *current = *stack;
	(void) linenum;

	while (current)
	{
		if (current->n == 0 || current->n < 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
