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
		while (ops[x].op)
		{
			if (ops[x].op[0] == format[i] &&
			ops[x].op[1] == format[i + 1])
			{
				_strcat(dest, ops[x].f(ap);
				i++;
				break;
			}
		}

	}
	va_end(ap);
}


