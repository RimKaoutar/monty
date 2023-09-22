#include "monty.h"

/**
  * nop -func that doesn’t do anything
  * @stack: head of the stack
  * @line_number: line on which the error occurred
  *
  * Return: Nothing
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
