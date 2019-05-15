#include "monty.h"

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
			dprintf(2, "L%d: unknown instruction %s\n", info.line_number, opcode);
			garbage_collection();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
