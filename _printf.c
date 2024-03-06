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
	int i, r;
	int len;
	int *reslen = &r;
	va_list ap;
	int (*func)(va_list, int *);

	if (format == NULL)
		return (-1);

	len = _strlenconst(format);
	*reslen = len;

	va_start(ap, format);
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			func = get_printf_function(format[i + 1]);
			if (func)
			{
				if (func(ap, reslen) == -1)
					return (-1);
			}
			i++;
		}
		else
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
