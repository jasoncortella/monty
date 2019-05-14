#include "monty.h"

/**
 * add_node_push - adds a new node at the beginning of a stack_t list.
 * @head: Pointer to the head of the list
 * @n: The value of the new node
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_node_push(stack_t **head, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);
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
 */
size_t pall_list(const stack_t *head)
{
	size_t i;

	for (i = 0; head; i++, head = head->next)
		printf("%d\n", head->n);
	return (i);
}
