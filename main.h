#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
char *_strcatconst(char *, const char *);
char *_strcat(char *, char *);
char *_strappendconst(char *dest, const char *src, int n);
int _putchar(char c);

int _printf(const char *format, ...);
int _printf_print(char *);

void *op_char(va_list, char *);
void *op_string(va_list, char *);
void *op_percent(va_list, char *);
void *op_decimal(va_list, char *);

#endif
