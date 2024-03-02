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
	int i, x;
	int len;
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

	result = calloc(sizeof(char), len + 1);
	if (result == NULL)
		return (0);

	va_start(ap, format);

	i = 0;
	while (i < len)
	{
		x = 0;
		while ((ops[x].op) && (i < len - 1))
		{
			if ((ops[x].op[0] == format[i]) && (ops[x].op[1] == format[i + 1]))
			{
				ops[x].f(ap, result);
				i++;
				break;
			}
			x++;
		}
		if (ops[x].op == NULL)
			result = _strncpy(result, (format + i), 1);

	printf("the result is [%s]\n", result);
		i++;
	}

	va_end(ap);


	printf("the result is [%s]\n", result);
	return (_printf_print(result));
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
