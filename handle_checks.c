#include "monty.h"

/**
  * check_args_num - Check the arguments passed on to the interpreter
  * @argn: Number of args
  *
  * Return: Nothing
  */

void check_args_num(int argn)
{
	if (argn != MIN_ARGS)
		handle_error(ERR_USAGE, NULL, 0, NULL);
}

/**
  * check_read_permission - Checks if the user has permissions to read the file
  * @filename: The path to the file
  *
  * Return: Nothing
  */

void check_read_permission(char *filename)
{
	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
  * check_push_data - Check the data of the push instruction
  * @data: The parameter to be validated.
  *
  * Return: 0 if data is valid or errcode if is invalid.
  */
int check_push_data(char *data)
{
	if (data == NULL || check_digits(data) == 0)
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

int check_digits(char *s)
{
	while (*s != '\0')
	{
		if (s[0] == '-')
		{
			s++;
			continue;
		}

		if (isdigit(*s) == 0)
			return (0);

		s++;
	}

	return (1);
}
