#include "monty.h"

/**
  * free_stack - Frees all nodes in the stack (doubly-linked list)
  *
  * Return: Nothing
  */

void free_stack(void)
{
	stack_t *current = NULL;

	if (head != NULL)
	{
		current = head;

		while (current)
		{
			head = head->next;
			free(current);
			current = head;
		}
	}
}

/**
  * count_stack - Counts the number of elements in the stack
  * @stack: Head of the stack to count
  *
  * Return: Number of elements in the stack
  */

unsigned int count_stack(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int len = 0;

	while (current)
	{
		len++;
		current = current->next;
	}

	return (len);
}
