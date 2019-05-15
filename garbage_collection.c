#include "monty.h"

/**
 * garbage_collection - frees all mallocced data structures
 */
void garbage_collection(void)
{
	fclose(info.monty_file);
	free(info.line);
	free_stack(info.stack);
}
