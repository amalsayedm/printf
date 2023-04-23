#include "main.h"

unsigned int link_sbase(container_s * output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int link_ubase(container_s *output,
		unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

/**
 * link_sbase - Converts a signed long to an inputted base and stores it
 * @output: containing a character array
 * @num: A signed long to be converted
 * @base: A pointer to a string
 * @flags: Flag modifier
 * @wid: A width modifier
 * @prec: A precision modifier*
 * Return: The number of bytes stored to the buffer.
 */
unsigned int link_sbase(container_s *output, long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	int size;
	char digit, zero = '0';
	unsigned int turn = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		turn += link_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--)
			turn += _memcpy(output, &zero, 1);
		if (NEG_FLAG == 0)
		{
			zero = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				turn += _memcpy(output, &zero, 1);
		}
	}
	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);
	return (turn);
}

/**
 * link_ubase - Converts an unsigned long to an inputted base &stores
 * @output: character array
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * Return: The number of bytes
 */
unsigned int link_ubase(container_s *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec)
{
	unsigned int size, turn = 1;
	char digit, zero = '0', *XO = "0x";

	for (size = 0; *(base + size);)
		size++;
	if (num >= size)
		turn += link_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--)
			turn += _memcpy(output, &zero, 1);
		if (NEG_FLAG == 0)
		{
			zero = (ZERO_FLAG == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				turn += _memcpy(output, &zero, 1);
		}
		if (((flags >> 5) & 1) == 1)
			turn += _memcpy(output, XO, 2);
	}
	digit = base[(num % size)];
	_memcpy(output, &digit, 1);
	return (turn);
}
