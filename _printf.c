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

	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);

	va_start(ap, format);

	for (i = 0; i < len; i++)
	{
		x = 0;
		while (ops[x].op)
		{
			if (ops[x].op[0] == format[i] &&
			ops[x].op[1] == format[i + 1])
			{
				_strcat(result, ops[x].f(ap));
				i++;
				break;
			}
			x++;
		}

	}
	va_end(ap);
	return (len);
}


