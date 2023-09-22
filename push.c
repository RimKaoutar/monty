#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @n: The n to push on the stack
  *
  * Return: Nothing
  */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		handle_error(ERR_MALLOC, NULL, 0, NULL);

	new->n = n;
	if (*stack)
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		*stack = new;
		return;
	}

	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @n: The value to push on the stack
  *
  * Return: Nothing
  */
void push_queue(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL, *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		handle_error(ERR_MALLOC, NULL, 0, NULL);

	new->n = n;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		new->next = NULL;
		new->prev = current;
		current->next = new;
		return;
	}

	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
