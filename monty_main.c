#include "monty.h"

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
		line_number = i + 1;
		printf("line %i: %s", line_number, line);
		opcode = line[0] // push
		argument = line[1] // 4
		arr =
			{"push", add_node_push},
			{"pall", pall_list}
		if (!valid_command)
	   		dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		if (valid_argument)
			push(STACK, argument)
		else:
	   		dprintf(2, "L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		i++;
	}

	fclose(monty_file);
	return (EXIT_SUCCESS);
}
