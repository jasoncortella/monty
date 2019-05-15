#include "monty.h"

info_t info = {NULL, NULL};

/**
 * main - entry point
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: As of yet undecided
 */
int main(int argc, char **argv)
{
	register int i = 0, opresult;
	ssize_t read;
	char *copy, *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	info.line = NULL;
	/* validate correct num of arguments */
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* open file */
	info.monty_file = fopen(argv[1], "r");
	if (!info.monty_file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&info.line, &len, info.monty_file)) != -1)
	{
		line_number = i + 1;
		opcode = strtok(info.line, " ");
		if (strcmp(opcode, "\n") == 0)
		{
			i++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			copy = strtok(NULL, " ");
			push_add_node(&stack, copy);
			i++;
			continue;
		}
		opresult = op_helper(&stack, opcode, line_number); /* find and execute op */
		if (opresult == -1) /* if no match found */
		{
			dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(info.monty_file);
			free_stack(stack);
			free(info.line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	fclose(info.monty_file);
	free(info.line);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
