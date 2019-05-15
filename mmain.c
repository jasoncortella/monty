#include "monty.h"

info_t info = {NULL, NULL, NULL, 0};


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
	garbage_collection();
	return (EXIT_SUCCESS);
}
