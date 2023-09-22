#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the stack
 * @linenum: Line number
 * 
 * Description:
 * This function prints the char represented by the top element of
 * the stack.
 * It first checks if the stack is empty and handles error.
 * Then it checks if the integer value is within the ASCII range(0-127)
 * If in range, it prints the char, else handles out of range error.
 * This allows representation of integers as chars for certain opcodes.
 * 
 * Return: None
 */
void pchar(stack_t **stack, unsigned int linenum)
{
	if (*stack == NULL)
		error_manager(ERR_PCHAR_E, NULL, linenum, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		error_manager(ERR_PCHAR_F, NULL, linenum, NULL);
}
