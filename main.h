#ifndef _MAIN_H_
#define _MAIN_H_

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	char *(f)(const char *format, int i);
} op_t;

int _strlen(char *);
int _printf(const char *format, ...);
char *op_char(va_list ap);
char *op_string(va_list ap);
char *op_percent(va_list ap);

#endif
