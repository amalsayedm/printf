#include "main.h"

/**
 * link_s - Converts a string and
 * @args: argument
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A container_s struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int link_s(container_s *output, va_list args,
			unsigned char flags, int wid, int prec, unsigned char len)
{
	char *sg, *empty = "(null)";
	int size;
	unsigned int turn = 0;
	(void)flags;
	(void)len;

	sg = va_arg(args, char *);
	if (sg == NULL)
		return (_copy(output, empty, 6));
	for (size = 0; *(sg + size);)
		size++;
	turn += getstring_width(output, flags, wid, prec, size);
	prec = (prec == -1) ? size : prec;
	while (*sg != '\0' && prec > 0)
	{
		turn += _copy(output, sg, 1);
		prec--;
		sg++;
	}
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_S - converts an argument to a string
 * @args: argument
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: contain character array
 * Return: The number of bytes stored.
 */

unsigned int link_S(container_s *output, va_list args,
			unsigned char flags, int wid, int prec, unsigned char len)
{
	char *sg, *empty = "(null)", *symb = "\\x", zero = '0';
	int size, index;
	unsigned int turn = 0;

	(void)len;
	sg = va_arg(args, char *);
	if (sg == NULL)
		return (_copy(output, empty, 6));

	for (size = 0; sg[size];)
		size++;
	turn += getstring_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(sg + index) != '\0' && index < prec; index++)
	{
		if (*(sg + index) < 32 || *(sg + index) >= 127)
		{
			turn += _copy(output, symb, 2);
			if (*(sg + index) < 16)
				turn += _copy(output, &zero, 1);
			turn += linker_ubase(output, *(sg + index),
					"0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		turn += _copy(output, (sg + index), 1);
	}
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_R - Reverses a string and stores it
 * @args: argument of reversed string
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array.
 * Return: The number of bytes stored
 */

unsigned int link_r(container_s *output, va_list args, 
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *sg, *empty = "(null)";
	int size, end, i;
	unsigned int turn = 0;

	(void)flags;
	(void)len;

	sg = va_arg(args, char *);
	if (sg == NULL)
		return (_copy(output, empty, 6));
	for (size = 0; *(sg + size);)
		size++;
	turn += getstring_width(output, flags, wid, prec, size);
	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		turn += _copy(output, (sg + end), 1);
		end--;
	}
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_R - Converts a string to ROT13 and stores it
 * @args: A va_list pointing to the string to be converted
 * @flags: Flag modifier
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A lenth modifier
 * @output: contain character array.
 * Return: The number of bytes stored
 */

unsigned int link_R(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *sg, *empty = "(null)";
	int i, j, size;
	unsigned int turn = 0;

	(void)flags;
	(void)len;
	sg = va_arg(args, char *);
	if (sg == NULL)
		return (_copy(output, empty, 6));
	for (size = 0; *(sg + size);)
		size++;
	turn += getstring_width(output, flags, wid, prec, size);
	prec = (prec == -1) ? size : prec;
	for (i = 0; *(sg + i) != '\0' && i < prec; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(sg + i) == *(abc + j))
			{
				turn += _copy(output, (rot13 + j), 1);
				break;
			}
		}
			if (j == 52)
			turn += _copy(output, (sg + i), 1);
	}
		turn += getneg_width(output, turn, flags, wid);
		return (turn);
}
