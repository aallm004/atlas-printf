#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_char- a function to return a character from a valist
 *
 * @ap:     the valist
 * @result: the output string
 *
 * Return:  a string array of one character
 *
 */

void *op_char(va_list ap, char *result)
{
	char s = va_arg(ap, int);

	/* the token length is two and the char length is one. */
	/* so shorten the memory by one byte. */
	result = realloc(result, (_strlen(result) - 1));
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

void *op_string(va_list ap, char *result)
{
	char *s = va_arg(ap, char *);
	int len = _strlen(result);
	int reslen = _strlen(s);

	if (reslen != 2) /* token length is always two right now */
	{
		result = realloc(result, len + (reslen - 2));
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

void *op_percent(va_list ap, char *result)
{
	ap = ap;

	/* the token length is two and the char length is one. */
	/* so shorten the memory by one byte. */
	result = realloc(result, (_strlen(result) - 1));
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

void *op_decimal(va_list ap, char *result)
{
	char s[] = "x";

	ap = ap;

	result = _strcat(result, s);

	return (0);
}
