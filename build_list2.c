#include "monty.h"

/**
 * add_list - adds the top two elements of the stack
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void add_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n += current->n;
	pop_list(stack, line_number);
}

/**
 * nop_list - doesn’t do anything
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void nop_list(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_list - subtracts the top element of the stack from the second top
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void sub_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n -= current->n;
	pop_list(stack, line_number);
}

/**
 * div_list - divides the second top element of the stack by the
 * top element of the stack
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void div_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
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
	next->n /= current->n;
	pop_list(stack, line_number);
}

/**
 * mul_list - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void mul_list(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *next;

	if (!current || !current->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		garbage_collection();
		exit(EXIT_FAILURE);
	}
	next = current->next;
	next->n *= current->n;
	pop_list(stack, line_number);
}
