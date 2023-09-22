#include "monty.h"

/**
 * open_file - Opens a file for reading
 * @filename: Name of the file to open
 * 
 * Description:
 * This function opens the given file and returns a FILE pointer.
 * It first calls check_read_permission() to validate permissions.
 * It then attempts to open the file in read mode using fopen().
 * If fopen() fails, an error message is printed and the program exits.
 * The FILE pointer is returned upon success.
 * This provides a way to centrally handle file opening and permissions.
 * 
 * Return: FILE pointer if success, exits on failure
*/
FILE *open_file(char *filename)
{
	FILE *file = NULL;

	check_read_permission(filename);

	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
