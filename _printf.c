#include "main.h"
#include <stdlib.h>
/**
 * _printf - A function that produces output according to a format.
 *
 * @format: Format string composed of directives: c, s, %
 *
 * Return: The number  of characters printed, excluding null byte
 */

int _printf(const char *format, ...)
{
	int i, x, r;
	int len;
	int *reslen = &r;
	va_list ap;
	char *result;
	op_t ops[] = {
		{"%c", op_char},
		{"%s", op_string},
		{"%%", op_percent},
		{"%d", op_decimal},
		{"%i", op_decimal},
		{NULL, NULL}
	};
	
	len = _strlenconst(format);
	*reslen = len;
	result = calloc(sizeof(char), *reslen + 1);
	
	if (result == NULL)
		return (0);
	
	va_start(ap, format);

	i = 0;
	while (i < len)
	{
		x = 0;
		while ((ops[x].op))
		{
			if ((ops[x].op[0] == format[i]) && (ops[x].op[1] == format[i + 1]))
			{
				if (ops[x].f(ap, result, reslen))
					return (0);
				i++;
				break;
			}
			x++;
		}
		if (ops[x].op == NULL)
			result = _strncatconst(result, (format + i), 1);

		i++;
	}

	va_end(ap);
	*reslen = _printf_print(result);

/*	free (result);*/

	return (*reslen);
}

/**
 * _printf_print-  print the result to std out
 *
 * @result:        the thing to print
 *
 * Return:         how long the thing is
 *
 */

int _printf_print(char *r)
{
	int i = 0;
	int x = _strlen(r);

	while (i < x)
	{
		_putchar(r[i]);
		i++;
	}

	return (x);
}
