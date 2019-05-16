#include "monty.h"

/**
 * mod_list - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void mod_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n %= current->n;
	pop_list(stack, line_number);
}

/**
 * pchar_list - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void pchar_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	if (current->n < 0 || current->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, ", line_number);
		dprintf(STDERR_FILENO, "value out of range\n");
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	putchar(current->n);
	putchar('\n');
}

/**
 * pstr_list - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void pstr_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current && current->n != 0)
	{
		if (current->n < 0 || current->n > 127)
			break;
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}

/**
 * rotl_list - rotates the stack to the top
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void rotl_list(stack_t **stack, unsigned int line_number)
{
	register int tmp;
	stack_t *current = *stack, *next;

	(void)line_number;
	if (current)
	{
		next = current->next;
		tmp = current->n;
		while (current->next)
		{
			current->n = next->n;
			current = next;
			next = current->next;
		}
		current->n = tmp;
	}
}

/**
 * rotr_list - rotates the stack to the bottom
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void rotr_list(stack_t **stack, unsigned int line_number)
{
	register int tmp;
	stack_t *current = *stack, *prev;

	(void)line_number;
	if (current)
	{
		while (current->next)
			current = current->next;
		prev = current->prev;
		tmp = current->n;
		while (current->prev)
		{
			current->n = prev->n;
			current = prev;
			prev = current->prev;
		}
		current->n = tmp;
	}
}
