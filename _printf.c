#include "main.h"
#include <stdarg.h>
/**
 * _printf - A function that produces output according to a format.
 *
 * @format: Format string composed of directives: c, s, %
 *
 * Return: The number  of characters printed, excluding null byte
 */

int _printf(const char *format, ...)
{
	int i;
	op_t ops;
	int len;
	va_list ap;

	len = _strlen(*format);

	va_start(ap, format);

	for (i = 0; i < len; i++)
	{
		if (*(ops[i].op) == format[0])
			ops[i].f(format, i);
	}
	va_end(ap);
}





/**
 * _strlen - returns the length of a string
 *
 * @s : int
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int x;

	x = 0;

	while (s[x] != '\0')
	{
		x++;
	}

	return (x);
}
