#include "monty.h"

/**
 * push_add_node_end - adds a new node at the end of a stack_t list
 * @value: value of new node
 */
void push_add_node_end(char *value)
{
	register int n;
	stack_t *new, *current = info.stack;
	char *ptr = NULL;

	ptr = strchr(value, '\n');
	if (ptr)
		*ptr = 0;
	if (!strlen(value) || !is_valid_num(value))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", info.line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!current)
	{
		new->prev = NULL;
		info.stack = new;
		return;
	}
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}
