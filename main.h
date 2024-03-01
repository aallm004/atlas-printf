#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	char *(*f)(va_list);
} op_t;

int _strlen(char *);
int _strlenconst(const char *);
char *_strcat(char *, char *);
int _printf(const char *format, ...);
char *op_char(va_list ap);
char *op_string(va_list ap);
char *op_percent(va_list ap);
char *op_decimal(va_list ap);
char *_strncpy(char *dest, char *src, int n);

#endif
