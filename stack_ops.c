#include "monty.h"

/**
  * free_stack - Frees all nodes in the stack (doubly-linked list)
  *
  * Return: Nothing
  */

void free_stack(void)
{
	stack_t *curr = NULL;

	if (head)
	{
		curr = head;

		while (curr)
		{
			head = head->next;
			free(curr);
			curr = head;
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
	stack_t *curr = stack;
	unsigned int lenght = 0;

	while (curr)
	{
		lenght++;
		curr = curr->next;
	}

	return (lenght);
}
