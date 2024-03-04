#include "main.h"

/**
 * _printf - A function that produces output according to a format.
 *
 * @format:  Format string composed of directives: c, s, %
 *
 * Return:   The number  of characters printed, excluding null byte
 *           -1 if there is trouble
 */

int _printf(const char *format, ...)
{
	int i, x, r;
	int len;
	int *reslen = &r;
	va_list ap;
	op_t ops[] = {
		{"%c", op_char}, {"%s", op_string}, {"%%", op_percent},
		{"%d", op_decimal}, {"%i", op_decimal}, {"%\0", op_nothing},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	len = _strlenconst(format);
	*reslen = len;

	va_start(ap, format);
	for (i = 0; i < len; i++)
	{
		for (x = 0; (ops[x].op); x++)
		{
			if ((ops[x].op[0] == format[i]) && (ops[x].op[1] == format[i + 1]))
			{
				if (ops[x].f(ap, reslen) == -1)
					return (-1);
				i++;
				break;
			}
		}
		if (ops[x].op == NULL)
			write(1, (format + i), 1);
	}

	va_end(ap);

	return (*reslen);
}

/**
 * _printf_print-  print the result to std out
 *
 * @r:             the thing to print
 * @l:             how long the thing is
 *
 */

void _printf_print(char *r, int *l)
{
	int i;

	for (i = 0; i < (*l); i++)
		_putchar(r[i]);

}
