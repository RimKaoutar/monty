#include "monty.h"

/**
  * nop -func that doesn’t do anything
  * @stack: head of the stack
  * @line_number: line on which the error occurred
  *
  * Return: Nothing
  */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
  return; /* nothing to do */
}
