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
 * _printf_helper - helper function
 * @format: string to print
 * @output: struct containing a string.
 * @args: list of arguments.
 * Return: The number of characters stored to output.
*/

int _printf_helper(const char *format, va_list args, container_s *output)
{
	int i, width, prec, rest = 0;
	char tmp;
	unsigned char flags, lenth;
	unsigned int (*f)(container_s *, va_list,
			unsigned char, int, int, unsigned char);

	for (i = 0; *(format + i); i++)
	{
		lenth = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flags = handleflag(format + i + 1, &tmp);
			width = handlewidth(args, format + i + tmp + 1, &tmp);
			prec = handleprec(args, format + i + tmp + 1,
					&tmp);
			lenth = handlelen(format + i + tmp + 1, &tmp);

			f = handle_specifiers(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				rest += f(output, args, flags, width, prec, lenth);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				rest = -1;
				break;
			}
		}
		rest += _copy(output, (format + i), 1);
		i += (lenth != 0) ? 1 : 0;
	}
	deallocate(args, output);
	return (rest);

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
	int ret = 0;

	if (format == NULL)
		return (-1);
	output = init_buffer();
	if (init_buffer() == NULL)
		return (-1);
	va_start(args, format);
	ret = _printf_helper(format, args, output);

	return (ret);
}
