#include "main.h"

/**
 * op_char- a function to return a character from a valist
 *
 * @ap:     the valist
 * @reslen: pointer to the length of the output string
 *
 * Return:  0 success
 *
 */

int op_char(va_list ap, int *reslen)
{
	char s;

	s = va_arg(ap, int);

	/* char is one byte less than token %c */
	*reslen = *reslen - 1;

	write(1, &s, 1);

	return (0);
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 * @reslen:   pointer to the length of the output string
 *
 * Return:    0 success
 *
 */

int op_string(va_list ap, int *reslen)
{
	char *s;
	int len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";

	len = _strlen(s);
	*reslen = *reslen + (len - 2);

	write(1, s, len);

	return (0);
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 * @reslen:    pointer to the length of the output string
 *
 * Return:     0 success
 *
 */

int op_percent(va_list ap, int *reslen)
{
	char percent = '%';

	ap = ap;

	/* the token length is two and '%' length is one. */
	/* shorten the output by one byte */
	*reslen = *reslen - 1;

	write(1, &percent, 1);

	return (0);
}

/**
 * op_decimal- a function to return a decimal from a valist
 *
 * @ap:        the va list
 * @reslen:    pointer to the length of the output string
 *
 * Return:     0 success
 *
 */

int op_decimal(va_list ap, int *reslen)
{
	char *s;
	int i;

	i = va_arg(ap, int);
	s = _itoa(i);
	*reslen = *reslen - 2;

	for (i = 0; (s[i] != '\0'); i++)
	{
		write(1, (s + i), 1);
		*reslen = *reslen + 1;
	}

	return (0);
}
