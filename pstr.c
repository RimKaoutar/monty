#include "monty.h"

/**
  * pstr - Prints the string starting at the top of the stack,
  *		   followed by a new line
  * @stack: The head of the stack
  * @linenum: Line number of the command in the bytecode file
  *
  * Return: Nothing
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
