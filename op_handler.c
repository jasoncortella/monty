#include "monty.h"

/**
 *op_helper - finds and executes a function based on opcode
 * ptbl: table of functions
 * @stack: double pointer to head of stack
 * @bcode: command to be executed
 * Return: -1 if op not found,
 *          0 if op executed successfully,
 */
int op_helper(stack_t **stack, char *bcode)
{
	register int i, op_ret = -1;
	char *op;
	instruction_t itbl[] = {
		{"pall", pall_list},
		/*
		   {"pint", pint_list},
		   {"pop", pop_list},
		   {"swap", swap_list},
		   {"add", add_list},
		   {"nop", nop_list},
		   {"sub", sub_list},
		   {"div", div_list},
		   {"mul", mul_list},
		   {"mod", mod_list},
		   {"pchar", pchar_list},
		   {"pstr", pstr_list},
		   {"rotl", rotl_list},
		   {"rotr", rotr_list},
		   {"stack", stack_list},
		   {"queue", queue_list},
		   */
		{NULL, NULL}
	};

	op = strtok(bcode, "\n");

	for (i = 0; itbl[i].opcode; i++)
	{
		if (strcmp(op, itbl[i].opcode) == 0)
		{
			itbl[i].f(stack, info.line_number);
			op_ret = 0;
			break;
		}
	}
	return (op_ret);
}
