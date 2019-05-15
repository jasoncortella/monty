#include "monty.h"

info_t info;

/**
 * push_add_node - adds a new node at the beginning of a stack_t list.
 * @head: Pointer to the head of the list
 * @n: The value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *push_add_node(stack_t **stack, char *copy)
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
	n = atoi(copy);
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	*stack = new;
	return (new);
}

/**
 * free_stack - frees a stack_t list.
 * @head: Pointer to the head of the list
 * Return: Nothing
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
 * @head: Pointer to the head of the list
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
