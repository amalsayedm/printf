#include "main.h"

/**
 * getstring_width - Stores leading spaces to a buffer for a width modifier.
 * @output: struct of the string
 * @flags: Flag
 * @wid: A width
 * @prec: A precision.
 * @size: The size of the string.
 * Return: bytes stored to the container
 */

unsigned int getstring_width(container_s *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _copy(output, &width, 1);
	}

	return (ret);
}
