#include "monty.h"

/**
 * mod_list - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void mod_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n %= current->n;
	pop_list(stack, line_number);
}

/**
 * pchar_list - prints the char at the top of the stack, followed by a new line
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void pchar_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	if ((current->n < 0) | (current->n > 127))
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	putchar(current->n);
	putchar('\n');
}

/**
 * pstr_list - prints the string starting at the top of the stack,
 * followed by a new line
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void pstr_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * rotl_list - rotates the stack to the top
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void rotl_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * rotr_list - rotates the stack to the bottom
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void rotr_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
