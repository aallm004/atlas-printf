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
	void *(*f)(va_list, char *);
} op_t;


int _strlenconst(const char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *_strcpy(char *dest, char *src);

int _printf(const char *format, ...);

void *op_char(va_list, char *);
void *op_string(va_list, char *);
void *op_percent(va_list, char *);
void *op_decimal(va_list, char *);

#endif
