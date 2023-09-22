#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @data: The data to push on the stack
  *
  * Return: Nothing
  */
void push(stack_t **stack, unsigned int data)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		handle_error(ERR_MALLOC, NULL, 0, NULL);

	new_node->n = data;
	if (*stack)
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @data: The value to push on the stack
  *
  * Return: Nothing
  */
void push_queue(stack_t **stack, unsigned int data)
{
	stack_t *current = NULL, *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		handle_error(ERR_MALLOC, NULL, 0, NULL);

	new_node->n = data;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		new_node->next = NULL;
		new_node->prev = current;
		current->next = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
