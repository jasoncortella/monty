#include "monty.h"

char *bcode;

/**
 * push_add_node - adds a new node at the beginning of a stack_t list.
 * @head: Pointer to the head of the list
 * @n: The value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *push_add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	char *opcode;
	int n;

	if (!new)
		return (NULL);
	opcode = strtok(bcode, " ");
	if (*pseudo* bcode is invalid) //note emsg below is unique to push
	{
		dprintf(2, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(bcode); //strtok modifies line, cuts first arg
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	*head = new;
	return (new);
}

/**
 * pall_list - prints all the elements of a stack_t list.
 * @head: Pointer to the head of the list
 * Return: the number of nodes
           0 if the function failed
 */
size_t pall_list(stack_t **stack, unsigned int line_number)
{
	size_t i;
	stack_t current = *stack;

	if (!current)
		return (0);
	for (i = 0; current; i++, current = current->next)
		printf("%d\n", current->n);
	return (i);
}
