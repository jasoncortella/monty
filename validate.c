#include "monty.h"

/**
 * validate_and_open - validate user input and open file
 * @argc: argument count
 * @filename: name of file to be open
 */
void validate_and_open(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	info.monty_file = fopen(filename, "r");
	if (!info.monty_file)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
