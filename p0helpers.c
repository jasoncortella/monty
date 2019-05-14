#include "monty.h"

/**
 *op_helper - finds and executes a function based on opcode
 * @ptbl: table of functions
 * Return: -1 if op not found,
 *          0 if op executed successfully,
 */
int op_helper(char *opcode)
{
	int i, op_ret = -1; // default return -1 if no match found
	instruction_t itbl[] = {
                {"push", add_node_push},
                {"pall", pall_list},
                {NULL, NULL}
        };

	for (i = 0; itbl[i].opcode; i++) //run through itbl
		if (strcmp(opcode, itbl[i].opcode) == 0) //op found
		{
			if (itbl[i].f(stack, line_number)) //op successful
				op_ret = 0;
			break;
		}
	return (op_ret);
}
