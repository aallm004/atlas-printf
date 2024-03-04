#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	int (*f)(va_list, int *);
} op_t;


int _strlenconst(const char *);
int _strlen(char *);
char *_strcatconst(char *, const char *);
char *_strncatconst(char *, const char *, int);
char *_strcat(char *, char *);
char *_strcatc(char *dest, char src);
char *_strappendconst(char *dest, const char *src, int n);
int _putchar(char c);
char *_itoa(int num);

int _printf(const char *format, ...);
void _printf_print(char *, int *);

int op_char(va_list, int *);
int op_string(va_list, int *);
int op_percent(va_list, int *);
int op_decimal(va_list, int *);
int op_nothing(va_list, int *);

#endif
