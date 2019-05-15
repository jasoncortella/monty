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
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	info.monty_file = fopen(filename, "r");
	if (!info.monty_file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}


/**
 * read_lines - read instructions from file and processes it
 */
void read_lines(void)
{
	register int i = 0, opresult = 0;
	size_t len = 0;
	ssize_t read;
	char *opcode, *copy;

	while ((read = getline(&info.line, &len, info.monty_file)) != -1)
	{
		info.line_number = i + 1;
		opcode = strtok(info.line, " ");
		if (strcmp(opcode, "\n") == 0)
		{
			i++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			copy = strtok(NULL, " ");
			push_add_node(copy);
			i++;
			continue;
		}
		opresult = op_helper(&info.stack, opcode);
		if (opresult == -1)
		{
			dprintf(STDERR_FILENO, "L%d: ", info.line_number);
			dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
			garbage_collection();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/**
 * garbage_collection - frees all mallocced data structures
 */
void garbage_collection(void)
{
	fclose(info.monty_file);
	free(info.line);
	free_stack(info.stack);
}
