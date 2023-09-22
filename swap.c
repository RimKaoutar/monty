#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of calling function
 * This function swaps the top two elements of the stack.
 * It first counts the number of elements and checks for min of 2.
 * A temporary variable is used to hold the first element.
 * The elements are then swapped:
 * Second element is assigned to first
 * Temporary variable is assigned to second
 * This implements swapping without removing from stack.
 * If stack is empty or has less than 2 elements, an error is handled.
 *
 * Return: None
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int len = 0, tmp = 0;

	len = count_stack(*stack);

	if (len < 2)
		error_manager(ERR_SWAP, NULL, line_number, NULL);

	if (*stack != NULL)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
