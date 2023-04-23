#include "main.h"

unsigned int link_x(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_X(va_list args, container_s *output,
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

unsigned int link_x(va_list args, container_s *output,
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
		turn += _memcpy(output, XO, 2);
	if (!(num == 0 && prec == 0))
		turn += link_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_X - Converts an unsigned int argument to hex using ABC
 * @args:  argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * Return: The number of bytes
 */
unsigned int link_X(va_list args, container_sr_s *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int turn = 0;

	char *XO "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;
	if (HASH_FLAG == 1 && num != 0)
		turn += _memcpy(output, XO2);
	if (!(num == 0 && prec == 0))
		turn += link_ubase(output, num, "0123456789ABCDEF",
				flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}
