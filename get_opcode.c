#include "monty.h"

/**
 * get_opcode - Gets the function associated with an opcode
 * @s: Opcode string
 * 
 * Description:
 * This function maps opcodes to their corresponding functions.
 * It contains an array of structs with opcode strings paired
 * with function pointers.
 * It iterates through the array comparing the passed opcode
 * string to each array element.
 * If a match is found, the associated function pointer is
 * returned.
 * If no match, NULL is returned.
 * This allows lookup and calling of the right function based
 * on opcode read from file.
 * 
 * Return: Function pointer if found, NULL if not found
 */

void (*get_opcode(char *s))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t opcodes[] = {
		{ "push_queue", push_queue },
		{ "pchar", pchar },
		{ "div", divide },
		{ "push", push },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "pstr", pstr },
		{ "rotl", rotl },
		{ "rotr", rotr },
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "mul", mul },
		{ "mod", mod },
		{ NULL, NULL }
	};

	while (opcodes[i].opcode)
	{
		if (strcmp(s, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
