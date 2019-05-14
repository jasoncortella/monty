#include "monty.h"

/**
 *op_helper - finds and executes a function based on opcode
 * @ptbl: table of functions
 * Return: -1 if op not found,
 *          0 if op executed successfully,
 */
int op_helper(stack_t **stack, char *bcode, int line_number)
{
	int i, op_ret = -1; /* default return -1 if no match found */
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
	char *op;

	op = strtok(bcode, "\n");

	for (i = 0; itbl[i].opcode; i++)
	{
		if (strcmp(op, itbl[i].opcode) == 0)
		{
			itbl[i].f(stack, line_number);
			op_ret = 0;
			break;
		}
	}
	return (op_ret);
}
