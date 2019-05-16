#include "monty.h"

/**
 * push_add_node - adds a new node at the beginning of a stack_t list
 * @value: value of new node
 */
void push_add_node(char *value)
{
	register int n;
	stack_t *new;
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
	new->next = info.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	info.stack = new;
}

/**
 * pall_list - prints all the elements of a stack_t list
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
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
 * pint_list - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void pint_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 * pop_list - removes the top element of the stack
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void pop_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	free(current);
	*stack = next;
	current = *stack;
	if (current)
		current->prev = NULL;
}

/**
 * swap_list - swaps the top two elements of the stack.
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void swap_list(stack_t **stack, unsigned int line_number)
{
	register int tmp;
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	tmp = current->n;
	current->n = next->n;
	next->n = tmp;
}
