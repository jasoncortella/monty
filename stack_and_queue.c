#include "monty.h"

/**
 * set_stack - sets the format of the data to a stack (LIFO). This
 * is the default behavior of the program.
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.queue_status = false;
}

/**
 * set_queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.queue_status = true;
}
