#include "main.h"

/**
 * dealocate_container - Frees astruct
 * @dest: The struct
 */
void dealocate_container(container_s *dest)
{
	free(dest->start);
	free(dest);
}
