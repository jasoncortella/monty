#ifndef MONTY_H
#define MONTY_H

/* standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct info_s - info to access globally
 * @monty_file: file
 * @line: line
 * @stack: stack
 * @line_number: line number
 * @queue_status: off by default
 * Description: global struct with program info
 */
typedef struct info_s
{
	FILE *monty_file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
	_Bool queue_status;
} info_t;

extern info_t info;

/* build_list */
void push_add_node(char *copy);
void pall_list(stack_t **stack, unsigned int line_number);
void pint_list(stack_t **stack, unsigned int line_number);
void pop_list(stack_t **stack, unsigned int line_number);
void swap_list(stack_t **stack, unsigned int line_number);

/* build_list2 */
void add_list(stack_t **stack, unsigned int line_number);
void nop_list(stack_t **stack, unsigned int line_number);
void sub_list(stack_t **stack, unsigned int line_number);
void div_list(stack_t **stack, unsigned int line_number);
void mul_list(stack_t **stack, unsigned int line_number);

/* build_list3 */
void mod_list(stack_t **stack, unsigned int line_number);
void pchar_list(stack_t **stack, unsigned int line_number);
void pstr_list(stack_t **stack, unsigned int line_number);
void rotl_list(stack_t **stack, unsigned int line_number);
void rotr_list(stack_t **stack, unsigned int line_number);

/* stack_and_queue */
void set_stack(stack_t **stack, unsigned int line_number);
void set_queue(stack_t **stack, unsigned int line_number);

/* main_helpers */
void validate_and_open(int argc, char *argv);
void read_lines(void);
void op_helper(stack_t **stack, char *opcode);
void free_stack(stack_t *head);
void garbage_collection(void);

/* main_helpers_2 */
void push_add_node_end(char *value);

/* string_helpers */
_Bool is_valid_num(char *str);

/* main */
void init_info(void);

#endif
