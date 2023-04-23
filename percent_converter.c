#include "main.h"

unsigned int link_c(va_list args, container_s  * output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_percent(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_p(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * link_c - Converts an argument to an unsigned char and stores it
 * @args: argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * Return: The number of bytes stored
 */
unsigned int link_c(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int turn = 0;

	(void)prec;
	(void)len;

	c = va_arg(args, int);

	turn += get_width(output, turn, flags, wid);
	turn += _memcpy(output, &c, 1);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_percent - Stores a percent sign
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * Return: The number of bytes stored
 */

unsigned int link_percent(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int turn = 0;

	(void)args;
	(void)prec;
	(void)len;

	turn += get_width(output, turnn, flags, wid);
	turn += _memcpy(output, &percent, 1);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}

/**
 * link_p - Converts the address of an argument to hex and stores it
 * @args:  argument to be converted
 * @flags: Flag modifiers
 * @wid: A width modifier
 * @prec: A precision modifier
 * @len: A length modifier
 * @output: character array
 * Return: The number of bytes stored
 */
unsigned int link_p(va_list args, container_s *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *empty = "(nil)";
	unsigned long int address;
	unsigned int turn = 0;

	(void)len;

	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, empty, 5));
	flags |= 32;
	turn += link_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	turn += getneg_width(output, turn, flags, wid);
	return (turn);
}
