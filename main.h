#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct container - astruct.
 * @container: pointer to astring
 * @start: pointer to the start of the string
 * @size: The length of the string
 */
typedef struct container
{
	char *container;
	char *start;
	unsigned int size;
} container_s;

/**
 * struct linker - A linker struct.
 * @specifier: A specifier
 * @_func: linker tothe right function
 */

typedef struct linker
{
	unsigned char specifier;
unsigned int (*_func)(container_s *, va_list,
			unsigned char, int, int, unsigned char);
} linker_l;

int _printf(const char *format, ...);

/*linker functions*/
unsigned int link_c(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_s(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_di(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_percent(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_b(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_u(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_o(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_x(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_X(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_S(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_p(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_r(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int link_R(container_s *string, va_list args,
		unsigned char flags, int wid, int prec, unsigned char len);

/*helpers*/

container_s *init_buffer(void);
void dealocate_container(container_s *container);
unsigned int _memcpy(container_s *container, const char *src, unsigned int n);
unsigned int convert_sbase(container_s *container, long int no, char *base,
		unsigned char flags, int wid, int prc);
unsigned int convert_ubase(container_s *container, unsigned long int no,
char *base, unsigned char flags, int wid, int prc);

/**/

unsigned char handleflag(const char *flags, char *index);
unsigned char handlelen(const char *modifier, char *index);
int handlewidth(va_list args, const char *modifier, char *index);
int handleprec(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(va_list,
container_s *, unsigned char, int, int, unsigned char);


#endif
