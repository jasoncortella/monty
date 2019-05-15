#include "monty.h"

/**
 * add_list - prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void add_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n += current->n;
	pop_list(stack, line_number);
}

/**
 * nop_list - doesn’t do anything
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void nop_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_list - subtracts the top element of the stack from the second top
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void sub_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div_list - divides the second top element of the stack by the
 * top element of the stack
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void div_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * mul_list - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: Pointer to the head of the list
 * @line_number: line number of instruction
 * Return: Nothing
 */
void mul_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

