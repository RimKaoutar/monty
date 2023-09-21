#include "monty.h"

void push(stack_t **stack, unsigned int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed");
		return(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = *stack;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}

}
