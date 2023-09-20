#include "monty.h"

void pop(stack_t **stack)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		printf("L<line_number>: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}
	/*later done*/
}
