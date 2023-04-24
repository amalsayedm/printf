#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

#define SHORT 1
#define LONG 2

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
 * struct flag_s -flags struct.
 * @flag: aflag.
 * @value: The value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} array_f;

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
unsigned int _copy(container_s *container, const char *src, unsigned int n);
unsigned int linker_sbase(container_s *container, long int no, char *base,
		unsigned char flags, int wid, int prc);
unsigned int linker_ubase(container_s *container, unsigned long int no,
char *base, unsigned char flags, int wid, int prc);

/**/

unsigned char handleflag(const char *flags, char *index);
unsigned char handlelen(const char *modifier, char *index);
int handlewidth(va_list args, const char *modifier, char *index);
int handleprec(va_list args, const char *modifier, char *index);
unsigned int (*handle_specifiers(const char *specifier))(container_s *, 
va_list, unsigned char, int, int, unsigned char);


unsigned int get_width(container_s *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int getstring_width(container_s *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int getneg_width(container_s *output, unsigned int printed,
		unsigned char flags, int wid);

#endif
