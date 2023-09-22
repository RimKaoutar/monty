#include "monty.h"

/**
 * pop - Removes the top element from the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number
 * 
 * Description:
 * This function removes the top node of the stack.
 * It first checks for empty stack and handles error.
 * It assigns current as head and temp as a temporary node.
 * Then it checks if next node exists:
 * Sets current to next node
 * Updates prev pointer of next node
 * Updates stack pointer
 * If next is NULL, stack becomes empty.
 * Finally it frees the memory of temporary node.
 * This implements popping or removing the top element.
 *
 * Return: None
 */
void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		error_manager(ERR_POP, NULL, linenum, NULL);

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
