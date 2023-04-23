
#include "main.h"

/**
 * get_width - Stores leading spaces to a buffer for a width modifier
 * @output: Astruct
 * @printed: The number of characters already printed
 * @flags: Flag modifiers
 * @wid: A width modifier
 * Return: The number of bytes remained
 */
unsigned int get_width(container_s *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int rest = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			rest += _copy(output, &width, 1);
	}

	return (rest);
}
