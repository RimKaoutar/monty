#include "monty.h"

/**
 * check_args_num - Checks if the number of arguments passed is valid
 * @num: Number of program arguments
 * 
 * Description:
 * This function checks if the number of arguments passed to the
 * program is equal to the expected minimum number of arguments.
 * If the number is incorrect, the error handler is called to
 * handle the error.
 * 
 * Return: None
*/

void check_args_num(int num)
{
	if (num != MIN_ARGS)
		handle_error(ERR_USAGE, NULL, 0, NULL);
}

/**
 * check_read_permission - Checks if the given file can be read
 * @file: Name of the file to check read permission for
 * 
 * Description:
 * This function uses the access() system call to check if the
 * given file can be read. Access returns -1 on error.
 * If access returns an error, an error message is printed to
 * stderr and the program exits with EXIT_FAILURE status.
 * Otherwise, the file can be read and no error occurs.
 * 
 * Return: None
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
 * check_push_n - Checks if data is valid for pushing onto stack
 * @num: String to check
 * 
 * Description:
 * Checks if the given string contains only digit characters.
 * Returns ERR_PUSH if:
 * num is NULL
 * check_digits() returns 0, meaning num is empty or invalid
 * Otherwise returns VALID_DATA if num contains only digits.
 * This verifies data is in the proper format before allowing it
 * to be pushed onto the stack.
 * 
 * Return: ERR_PUSH (201) or VALID_DATA (0)
*/
int check_push_n(char *num)
{
	if (num == NULL || check_digits(num) == 0)
		return (ERR_PUSH);

	return (VALID_DATA);
}

/**
 * check_digits - Checks if a string contains only digit characters
 * @str: String to check
 * 
 * Description:
 * This function checks if a given string contains only digit characters.
 * It iterates through each character of the string. If the first character
 * is '-', it skips it to allow for negative numbers.
 * For each remaining character, it checks if it is a digit using isdigit().
 * If any non-digit character is found, it returns 0.
 * Otherwise it returns 1 if the full string contains only digits.
 * 
 * Return: 1 if only digits, 0 otherwise
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
