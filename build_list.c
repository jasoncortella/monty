#include "monty.h"

/**
 * push_add_node - adds a new node at the beginning of a stack_t list.
 * @value: The value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *push_add_node(char *value)
{
	register int n;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
	/* need to check if valid second argument */
	if (0)
	{
		dprintf(2, "L%d: usage: push integer", info.line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	new->n = n;
	new->next = info.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	info.stack = new;
	return (new);
}

/**
 * free_stack - frees a stack_t list.
 * @head: Pointer to the head of the list
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
 * pall_list - prints all the elements of a stack_t list.
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void pall_list(stack_t **stack, unsigned int line_number)
{
	size_t i;
	stack_t *current = *stack;

	(void)line_number;
	for (i = 0; current; i++, current = current->next)
		printf("%d\n", current->n);
}
