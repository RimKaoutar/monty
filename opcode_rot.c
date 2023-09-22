#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @stack: The head of the stack
  * @line_number: Line number of the command in the bytecode file
  *
  * Return: Nothing
  */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;
	(void) line_number;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

/**
  * rotl - Rotates the stack to the top
  * @stack: The head of the stack
  * @line_number: Line number of the command in the bytecode file
  *
  * Return: Nothing
  */
void rotl(stack_t **stack, unsigned int line_number)
{
	unsigned int temp = 0;
	stack_t *curr = *stack;
	(void) line_number;

	if (curr && curr->next)
	{
		while (curr->next)
		{
			temp = curr->n;
			curr->n = curr->next->n;
			curr->next->n = temp;
			curr = curr->next;
		}
	}
}
