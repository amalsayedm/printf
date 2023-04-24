#include "main.h"

unsigned int link_x(container_s * output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * link_x - Converts an unsigned int argument to hex using abc
 * @args:  argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array.
 * Return: The number of bytes stored
 */

unsigned int link_x(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int turn = 0;
	char *XO = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;
	if (HASH_FLAG == 1 && num != 0)
		turn += _copy(output, XO, 2);
	if (!(num == 0 && prec == 0))
		turn += linker_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * convert_X - Converts to hex using ABCDEF
 * @args: the argument
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: length
 * @output: A struct containing a string
 * Return: bytes stored to the buffer.
 */
unsigned int link_X(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _copy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += linker_ubase(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	ret += getneg_width(output, ret, flags, wid);

	return (ret);
}
