#include "monty.h"

void opcode_errors(int errnum, unsigned int line)
{
	switch (errnum)
	{
		case USAGE_ERROR:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case PUSH_ERROR:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		case PINT_ERROR:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case POP_ERROR:
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case SWAP_ERROR:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line);
			break;
		case ADD_ERROR:
			fprintf(stderr, "L%d: can't add, stack too short\n", line);
			break;
		case SUB_ERROR:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line);
			break;
		case DIV_ERROR:
			fprintf(stderr, "L%d: can't div, stack too short\n", line);
			break;
		case ZERODIV_ERROR:
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		case MUL_ERROR:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line);
			break;
		case MOD_ERROR:
			fprintf(stderr, "L%d: can't mod, stack too short\n", line);
			break;
		default:
			break;
	}
}
