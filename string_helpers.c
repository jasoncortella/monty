#include "monty.h"

/**
 * is_valid_num - checks if char arr is a valid number
 * Return: true or false
 */
_Bool is_valid_num(char *str)
{
	register int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue;
		}
		else if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}