#include "monty.h"

/**
  * check_args_num - Check the arguments passed on to the interpreter
  * @argn: Number of args
  *
  * Return: Nothing
  */

void check_args_num(int num)
{
	if (num != MIN_ARGS)
		handle_error(ERR_USAGE, NULL, 0, NULL);
}

/**
  * check_read_permission - Checks if the user has permissions to read the file
  * @filename: The path to the file
  *
  * Return: Nothing
  */

void check_read_permission(char *file)
{
	if (access(file, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
}

/**
  * check_push_data - Check the data of the push instruction
  * @data: The parameter to be validated.
  *
  * Return: 0 if data is valid or errcode if is invalid.
  */
int check_push_data(char *num)
{
	if (num == NULL || check_digits(num) == 0)
		return (ERR_PUSH);

	return (VALID_DATA);
}

/**
  * check_digits - Checks if all characters in a string are digits
  * @s: The string to be checked.
  *
  * Return: 1 if all if all evaluated characters are digits except
  *			for hyphens or 0 if not
  */

int check_digits(char *str)
{
	while (*str != '\0')
	{
		if (str[0] == '-')
		{
			str++;
			continue;
		}

		if (isdigit(*str) == 0)
			return (0);

		str++;
	}

	return (1);
}
