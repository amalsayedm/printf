#include "main.h"

/**
 * link_di - Converts an argument to a signed int & stores it
 * @args:  argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: A container_sr_s struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int link_di(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int d, copy;
	unsigned int turn = 0, count = 0;
	char zero, space = ' ', neg = '-', plus = '+';

	d = (len == LONG) ? va_arg(args, long int) : va_arg(args, int);
	if (len == SHORT)
		d = (short)d;

	if (SPACE_FLAG == 1 && d >= 0)
		turn += _copy(output, &space, 1);
	if (prec <= 0 && NEG_FLAG == 0)
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			turn += _copy(output, &plus, 1);
		if (ZERO_FLAG == 1 && d < 0)
			turn += _copy(output, &neg, 1);
		zero = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			turn += _copy(output, &zero, 1);
	}
	if (ZERO_FLAG == 0 && d < 0)
		turn += _copy(output, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		turn += _copy(output, &plus, 1);
	if (!(d == 0 && prec == 0))
		turn += linker_ubase(output, d, "0123456789",
				flags, 0, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_b - Converts an unsigned int argument to binaryand stores
 * @args:argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array.
 * Return: The number of bytes stored
 */

unsigned int link_b(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)len;

	return (linker_ubase(output, num, "01", flags, wid, prec));
}

/**
 * link_o - Converts an unsigned int to octal and tores
 * @args: A va_list poinitng to the argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * Return: The number of bytes
 */
unsigned int link_o(container_s *output, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int turn = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		turn += _copy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		turn += linker_ubase(output, num, "01234567",
				flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_u - Converts an unsigned int argument to decimal and stores
 * @args:  argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * return: The number of bytes stored to the buffer.
 */
unsigned int link_u(container_s *output, va_list args,
			unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int turn = 0;

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;
	if (!(num == 0 && prec == 0))
		turn += linker_ubase(output, num, "0123456789",
				flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}
