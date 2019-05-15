#include "monty.h"

/**
 * push_add_node - adds a new node at the beginning of a stack_t list.
 * @value: The value of the new node
 */
void push_add_node(char *value)
{
	register int n;
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* need to check if valid second argument */
	if (0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer", info.line_number);
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

/**
 * pint_list -prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void pint_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pop_list -  prints all the elements of a stack_t list
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void pop_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_list - prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void swap_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

