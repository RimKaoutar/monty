#include "monty.h"

/**
 * pop - func that removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: Line number of the command in the bytecode file
 *
 * Return: Nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		handle_error(ERR_POP, NULL, line_number, NULL);

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
