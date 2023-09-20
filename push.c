#include "monty.h"

void push(stack_t **stack, unsigned int n)
{
	stack_t new;
	stack_t current;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed");
		return(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		current = *stack;
		while(current && current->next)
			current = current->next;

		new->prev = current;
		current->next = new;
	}

}
