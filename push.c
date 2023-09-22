#include "monty.h"

/**
 * push - Adds a new node at the beginning of the stack
 * @stack: Double pointer to the stack
 * @n: Integer value to add
 * 
 * Description:
 * This function adds a new node with data 'n' to the stack.
 * It allocates memory for new node and handles malloc error.
 * The data is assigned to new node.
 * If stack is not empty:
 * New node next is current head
 * New node prev is head's prev
 * Head's prev is updated
 * Head is updated
 * If empty stack:
 * New node next is NULL
 * New node prev is NULL
 * Head is updated
 * This implements pushing or adding to the top of the stack.
 * 
 * Return: None
*/
void push(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_manager(ERR_MALLOC, NULL, 0, NULL);

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
 * push_queue - Adds a new element at the end of the queue
 * @stack: Double pointer to the queue
 * @n: Integer value to add
 * 
 * Description:
 * This function implements adding an element to a queue using a stack.
 * It allocates memory for new node and handles error.
 * If queue is not empty:
 * Iterate to the last node
 * Link new node as last
 * Update pointers
 * If empty queue:
 * Set next as NULL
 * Set prev as NULL
 * Update head
 * This treats the stack as a queue by adding to the end.
 * 
 * Return: None
*/
void push_queue(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL, *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		error_manager(ERR_MALLOC, NULL, 0, NULL);

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
