#include "monty.h"

/**
  * select_op - Select the operation that relates to the Monty instruction
  * @s: The instruction to be executed
  *
  * Return: Pointer to the function to be executed or
  *			NULL if the function don't exists
  */

void (*select_op(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
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
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
