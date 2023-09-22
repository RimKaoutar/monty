#include "monty.h"

/**
 * nop - Does nothing
 * @stack: Unused stack pointer
 * @line_number: Unused line number
 * 
 * Description:
 * The nop (no operation) opcode does not do anything.
 * The function parameters are declared as unused to avoid
 * compiler warnings.
 * It simply returns without any processing.
 * This provides a placeholder function for the nop opcode
 * as required by the specifications.
 * 
 * Return: None
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	return; /* nothing to do */
}
