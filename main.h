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

#endif
