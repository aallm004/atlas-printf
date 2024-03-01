#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * op_char - a function to return a character from a valist
 *
 * @ap:      the valist
 *
 * Returns:  a string array of one character
 *
 */

void *op_char(va_list ap, char *result)
{
	char s = va_arg(ap, char);

	result = _strcat(result, &s);

	return (0);
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 *
 * Return:    a string array of characters
 *
 */

void *op_string(va_list ap, char *result)
{
        char *s = va_arg(ap, char *);

	result = _strcat(result, s);

	return (0);
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 *
 * Return:     a string array of one %
 *
 */

void *op_percent(va_list ap, char *result)
{
	ap = ap;

	result = _strcat(result, "%");

	return (0);
}

/**
 * op_decimal- a function to return a decimal from a valist
 *
 * @ap:        the va list
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
