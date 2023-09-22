#include "monty.h"

/**
 * rotr - Rotates the stack to the right
 * @stack: Double pointer to the stack
 * @linenum: Line number (unused parameter)
 * 
 * Description:
 * This function rotates all elements of the stack to the right by one position.
 * It first checks for validity of the stack.
 * It then iterates to the tail (last node) of the stack:
 * tail pointer tracks the last node
 * tail->prev->next is made NULL to break link
 * tail's next is set to head
 * head is updated to tail
 * This implements right rotation by making the last
 * element the new head.
 * 
 * Return: None
 */
void rotr(stack_t **stack, unsigned int linenum)
{
	stack_t *tail = NULL;
	(void) linenum;

	if (*stack && (*stack)->next)
	{
		tail = *stack;

		while (tail->next != NULL)
			tail = tail->next;

		tail->prev->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}
/**
 * rotl - Rotates the stack to the left
 * @stack: Double pointer to the stack
 * @linenum: Line number (unused parameter)
 * 
 * Description:
 * This function rotates all elements of the stack to the left by one position.
 * It first checks for validity of the stack.
 * It then iterates through the stack, swapping each node's data with its next:
 * Stores current data in temp
 * Assigns next data to current
 * Assigns temp to next
 * This implements left rotation of the stack contents.
 * 
 * Return: None
 */
void rotl(stack_t **stack, unsigned int linenum)
{
	unsigned int temp = 0;
	stack_t *current = *stack;
	(void) linenum;

	if (current && current->next)
	{
		while (current->next)
		{
			temp = current->n;
			current->n = current->next->n;
			current->next->n = temp;
			current = current->next;
		}
	}
}
