#include "monty.h"

void garbage_collection(void)
{
	fclose(info.monty_file);
	free(info.line);
	free_stack(info.stack);
}
