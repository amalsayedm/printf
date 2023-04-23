#include "main.h"

/**
 * getneg_width - add space for a '-' flag.
 * @output: struct containing the string
 * @printed: stored to output
 *           for a given specifier.
 * @flags: Flag
 * @wid: A width
 * Return: bytes stored to the buffer.
 */
unsigned int getneg_width(container_s *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _copy(output, &width, 1);
	}

	return (ret);
}
