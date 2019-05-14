#include "monty.h"

int main(int argc, char **argv)
{
	register int count = 0, i = 0;
	FILE *monty_file;
	ssize_t read;
	char *line;
	size_t len = 0;
	char c;
	char **commands;
	extern stack_t STACK;

	/* global? */
	(void)STACK;

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

	/* get lines */
	for (c = getc(monty_file); c != EOF; c = getc(monty_file))
		if (c == '\n')
			count++;
	printf("This file has %d lines\n", count);
	commands = malloc(sizeof(char *) * (count + 1));

	/* read and copy lines */
	monty_file = fopen(argv[1], "r");
	while ((read = getline(&line, &len, monty_file)) != -1)
	{
		commands[i] = strdup(line);
		i++;
	}
	commands[i] = NULL;

	/* print lines */
	for (i = 0; commands[i]; i++)
	{
		printf("line %i: %s", i + 1, commands[i]);
	}

	/* Invalid instruction
	   dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
	   exit(EXIT_FAILURE);
	   */

	fclose(monty_file);
	return (EXIT_SUCCESS);
}
