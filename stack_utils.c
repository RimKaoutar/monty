#include "monty.h"

/**
 * _free - Frees the memory of an entire stack
 *
 * Description:
 * This function iterates through the stack and frees the memory of
 * each node.
 * It first checks if the head is not NULL to ensure the stack exists.
 * A current pointer tracks the node to be freed in each iteration.
 * The logic is:
 * Update head to next node
 * Free current node
 * Update current
 * This iterates through the entire stack, freeing each node.
 * Once complete, the stack is fully freed.
 *
 * Return: None
 */

void _free(void)
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
 * count_stack - Counts the number of nodes in a stack
 * @stack: Pointer to the head of the stack
 *
 * Description:
 * This function counts the number of nodes in a stack. It takes
 * a pointer to the head node as a parameter.
 * A current pointer tracks the traversal and len counts the nodes.
 * The logic is:
 * Initialize current to head
 * Iterate while current isn't NULL
 * Increment len
 * Advance current
 * Once the whole stack is traversed, len will contain
 * the number of nodes.
 * This allows obtaining the size or length of the stack.
 *
 * Return: Number of nodes in the stack
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
