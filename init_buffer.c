#include "main.h"

/**
 * init_buffer - Initializes a variable of struct type buffer_t.
 *
 * Return: A pointer to the initialized buffer_t.
 */
container_s *init_buffer(void)
{
	container_s *output;

	output = malloc(sizeof(container_s));
	if (output == NULL)
		return (NULL);

	output->container = malloc(sizeof(char) * 1024);
	if (output->container == NULL)
	{
		free(output);
		return (NULL);
	}

	output->start = output->container;
	output->size = 0;

	return (output);
}
