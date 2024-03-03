#include "main.h"

/**
 * op_char- a function to return a character from a valist
 *
 * @ap:     the valist
 * @result: the output string
 *
 * Return:  a string array of one character
 *
 */

void *op_char(va_list ap, char *result, int *reslen)
{
	char s = va_arg(ap, int);
	
	*reslen = *reslen - 1;

	/* the token length is two and the char length is one. */
	/* so shorten the memory by one byte. */
	result = realloc(result, *reslen + 1);
	if (result == NULL)
		return (NULL);

	result = _strcat(result, &s);

	return (0);
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 * @result:   the output string
 *
 * Return:    a string array of characters
 *
 */

void *op_string(va_list ap, char *result, int *reslen)
{
	char *s = va_arg(ap, char *);
	int s_len = _strlen(s);

	if (s_len != 2) /* token length is always two right now */
	{
		*reslen = *reslen + (s_len - 2);
		result = realloc(result, *reslen + 1);
		if (result == NULL)
			return (NULL);
	}

	result = _strcat(result, s);

	return (0);
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     a string array of one %
 *
 */

void *op_percent(va_list ap, char *result, int *reslen)
{
	ap = ap;
	*reslen = *reslen - 1;

	/* the token length is two and the char length is one. */
	/* so shorten the memory by one byte. */
	result = realloc(result, *reslen + 1);
	if (result == NULL)
		return (NULL);

	result = _strcat(result, "%");

	return (0);
}

/**
 * op_decimal- a function to return a decimal from a valist
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     a string array of numbers from the va list
 *
 */

void *op_decimal(va_list ap, char *result, int *reslen)
{
	char s[] = "x";

	ap = ap;
	*reslen = *reslen;

	result = _strcat(result, s);

	return (0);
}
