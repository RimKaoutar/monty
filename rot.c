#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @stack: The head of the stack
  * @linenum: Line number of the command in the bytecode file
  *
  * Return: Nothing
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
  * rotl - Rotates the stack to the top
  * @stack: The head of the stack
  * @linenum: Line number of the command in the bytecode file
  *
  * Return: Nothing
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
