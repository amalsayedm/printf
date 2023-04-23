#include "main.h"


/**
 * deallocate - cleanup memory
 * @args: arguments
 * @output: struct of the container
 */
void deallocate(va_list args, container_s *output)
{
	va_end(args);
	write(1, output->start, output->size);
	dealocate_container(output);
}


/**
 * _printf - print astring.
 * @format: contains directives.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	container_s *output;
	va_list args;
char tmp;
	int ret, i, wid, prec, ret = 0;
	unsigned char flags, len = 0;
	unsigned int (*f)(container_s *, va_list,
unsigned char, int, int, unsigned char);

	if (format == NULL)
		return (-1);
	if (init_buffer() == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; *(format + i); i++)
	{
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handleflag(format + i + 1, &tmp);
			wid = handlewidth(args, format + i + tmp + 1, &tmp);
			prec = handleprec(args, format + i + tmp + 1, &tmp);
			len = handlelen(format + i + tmp + 1, &tmp);
			if (handle_specifiers(format + i + tmp + 1) != NULL)
			{
				i += tmp + 1;
				ret += f(output, args, flags, wid, prec, len);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	deallocate(args, output);

	return (ret);
}
