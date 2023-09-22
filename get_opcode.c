#include "monty.h"

/**
  * get_opcode - Select the operation that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: Pointer to the function to be executed or
  *			NULL if the function don't exists
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
