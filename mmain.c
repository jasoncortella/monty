#include "monty.h"

info_t info = {NULL, NULL};

/**
 * main - entry point
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: As of yet undecided
 */
int main(int argc, char **argv)
{
	validate_and_open(argc, argv[1]);
	read_lines();
	fclose(info.monty_file);
	free(info.line);
	/*free_stack(stack);*/
	return (EXIT_SUCCESS);
}
