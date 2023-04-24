#include "main.h"

/**
 * handleflag - flags with value matching
 * @flag: pointer of string flags
 * @index: string
 * Return: flag's value
*/

	unsigned char handleflag(const char *flag, char *index)
{
	int i, j;
	unsigned char turn = 0;
	array_f flags[] = {
		{'+', PLUS},
		{' ', SPACE},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEG},
		{0, 0}
	};

	for (i = 0; flag[i]; i++)
	{
		for (j = 0; flags[j].flag != 0; j++)
		{
			if (flag[i] == flags[j].flag)
			{
				(*index)++;
				if (turn == 0)
					turn = flags[j].value;
				else
					turn |= flags[j].value;
				break;
			}
		}
		if (flags[j].value == 0)
			break;
	}
	return (turn);
}

/**
 * handlelen - length and value
 * @modifier: pointer of length
 * @index: counter for string
 * Return: lenght value
 */

unsigned char handlelen(const char *modifier, char *index)
{
	if (*modifier == 'h')
	{
		(*index)++;
		return (SHORT);
	}
	else if (*modifier == 'l')
	{
		(*index)++;
		return (LONG);
	}
	return (0);
}

/**
 * handlewidth - width and value
 * @args:va_list of arguments
 * @modifier: pointer
 * @index: counter for string
 * Return: width's value
 */

int handlewidth(va_list args, const char *modifier, char *index)
{
	int value = 0;

	while ((*modifier == '*') ||
			(*modifier >= '0' && *modifier <= '9'))
	{
		(*index)++;
		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}

/**
 * handleprec - modifier with value
 * @args: A va_list of arguments
 * @modifier: A pointer to a modifier
 * @index: counter for string
 * Return: modifier's value
 */

int handleprec(va_list args, const char *modifier, char *index)
{
	int value = 0;

	if (*modifier != '.')
		return (-1);
	modifier++;
	(*index)++;
	{
		if (*modifier == '0')
			(*index)++;
		return (0);
	}

	while ((*modifier == '*') ||
			(*modifier >= '0' && *modifier <= '9'))
	{(*index)++;
		if (*modifier == '*')
		{
			value = va_arg(args, int);
			if (value <= 0)
				return (0);
			return (value);
		}
		value *= 10;
		value += (*modifier - '0');
		modifier++;
	}
	return (value);
}

/**
 *  handle_specifiers - Matches specifier with function
 *  @specifier: pointer specifier
 *  Return: pointer to the function
 */

unsigned int (*handle_specifiers(const char *specifier))
	(container_s *, va_list, unsigned char, int, int, unsigned char)
{
	int i;
	linker_l linkers[] = {
		{'c', link_c},
		{'s', link_s},
		{'d', link_di},
		{'i', link_di},
		{'%', link_percent},
		{'b', link_b},
		{'u', link_u},
		{'o', link_o},
		{'x', link_x},
		{'X', link_X},
		{'S', link_S},
		{'p', link_p},
		{'r', link_r},
		{'R', link_R},
		{0, NULL}
	};

	for (i = 0; linkers[i]._func; i++)
	{
		if (linkers[i].specifier == *specifier)
			return (linkers[i]._func);
	}
	return (NULL);
}
