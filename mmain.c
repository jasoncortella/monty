#include "monty.h"

char *bcode;

/**
 * main - entry point
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: As of yet undecided
 */
int main(int argc, char **argv)
{
	register int i = 0;
	FILE *monty_file;
	ssize_t read;
	char *line, opcode;
	size_t len = 0;

	/* validate correct num of arguments */
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		bcode = line; //set global variable to getline input
		line_number = i + 1;
		printf("line %i: %s", line_number, line);
		opresult = op_helper(line_number); // find and execute op
		if (opresult == -1) // if no match found
		{
	   		dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fclose(monty_file);
	return (EXIT_SUCCESS);
}
