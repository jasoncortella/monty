#include "monty.h"

/**
 * push_add_node - adds a new node at the beginning of a stack_t list.
 * @head: Pointer to the head of the list
 * @n: The value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *push_add_node(stack_t **stack, char *line)
{
	stack_t *new = malloc(sizeof(stack_t));
	int n;

	if (!new)
		return (NULL);
/*	if (*pseudo* line is invalid) //note emsg below is unique to push
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
*/
	n = atoi(line); /* strtok modifies line, cuts first arg */
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	*stack = new;
	return (new);
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
