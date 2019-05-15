#include "monty.h"

info_t info;

void read_lines(void)
{
	register int i = 0, opresult = 0;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode, *copy;
	stack_t *stack = NULL;

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
		opresult = op_helper(&stack, opcode, line_number);
		if (opresult == -1)
		{
			dprintf(2, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(info.monty_file);
			free_stack(stack);
			free(info.line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
