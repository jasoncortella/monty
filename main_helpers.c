#include "monty.h"

/**
 * validate_and_open - validate user input and open file
 * @argc: argument count
 * @filename: name of file to be opened
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
 * read_lines - read instructions from file and process it
 */
void read_lines(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *value;

	while ((read = getline(&info.line, &len, info.monty_file)) != -1)
	{
		opcode = strtok(info.line, " ");
		if (*opcode == '#' || !strcmp(opcode, "\n"))
		{
			info.line_number++;
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			value = strtok(NULL, " ");
			info.queue_status
				? push_add_node_end(value)
				: push_add_node(value);
			info.line_number++;
			continue;
		}
		if (op_helper(&info.stack, opcode) == -1)
		{
			dprintf(STDERR_FILENO, "L%d: ", info.line_number);
			dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
			garbage_collection();
			exit(EXIT_FAILURE);
		}
		info.line_number++;
	}
}

/**
 *op_helper - finds and executes a function based on opcode
 * ptbl: table of functions
 * @stack: double pointer to head of stack
 * @bcode: command to be executed
 * Return: -1 if op not found,
 *          0 if op executed successfully,
 */
int op_helper(stack_t **stack, char *bcode)
{
	register int i, op_ret = -1;
	char *op;
	instruction_t itbl[] = {
		{"pall", pall_list},
		{"pint", pint_list},
		{"pop", pop_list},
		{"swap", swap_list},
		{"add", add_list},
		{"nop", nop_list},
		{"sub", sub_list},
		{"div", div_list},
		{"mul", mul_list},
		{"mod", mod_list},
		{"pchar", pchar_list},
		{"pstr", pstr_list},
		{"rotl", rotl_list},
		{"rotr", rotr_list},
		{"stack", set_stack},
		{"queue", set_queue},
		{NULL, NULL}
	};

	op = strtok(bcode, "\n");

	for (i = 0; itbl[i].opcode; i++)
	{
		if (strcmp(op, itbl[i].opcode) == 0)
		{
			itbl[i].f(stack, info.line_number);
			op_ret = 0;
			break;
		}
	}
	return (op_ret);
}

/**
 * free_stack - frees a stack_t list
 * @head: pointer to the head of the list
 */
void free_stack(stack_t *head)
{
	stack_t *tmp, *current = head;

	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
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
