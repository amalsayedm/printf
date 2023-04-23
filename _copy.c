#include "main.h"

/**
 * _copy - Copies src into dest
 * @dest: A struct.
 * @src: A pointer to string to copy.
 * @n: The number of bytes to be copied.
 * Return: The number of bytes copied.
 */
unsigned int _copy(container_s *dest, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(dest->container) = *(src + index);
		(dest->size)++;

		if (dest->size == 1024)
		{
			write(1, dest->start, dest->size);
			dest->container = dest->start;
			dest->size = 0;
		}

		else
			(dest->container)++;
	}

	return (n);
}
