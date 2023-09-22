#include "monty.h"

/**
 * pint - Prints the integer at the top of the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number
 *
 * Description:
 * This function prints the integer represented by the top element
 * of the stack.
 * It first checks if the stack is empty and handles error.
 * It then simply prints the integer value of the top element.
 * This provides a way to print the integer on top of the stack.
 *
 * Return: None
*/
void pint(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL)
		error_manager(ERR_PINT, NULL, linenum, NULL);

	printf("%d\n", (*stack)->n);
}
