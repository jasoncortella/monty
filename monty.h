#ifndef MONTY_H
#define MONTY_H

/* standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 *
 * Description: file and line
 */
typedef struct info_s
{
        FILE *monty_file;
	char *line;
	stack_t *stack;
	unsigned int line_number;
} info_t;

extern info_t info;

stack_t *push_add_node(char *copy);
void pall_list(stack_t **stack, unsigned int line_number);
int op_helper(stack_t **stack, char *line);
void free_stack(stack_t *head);
void validate_and_open(int argc, char *argv);
void read_lines(void);
void garbage_collection(void);

#endif
