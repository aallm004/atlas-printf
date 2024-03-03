#include "main.h"

/**
 * op_char- a function to return a character from a valist
 *
 * @ap:     the valist
 * @result: the output string
 *
 * Return:  0 success, -1 memory allocation failure
 *
 */

int op_char(va_list ap, char *result, int *reslen)
{
	char s;
	char *temp;

	s = va_arg(ap, int);

	/* the token length is two and the char length is one */
	/* so shorten the memory by one byte */
	*reslen = *reslen - 1;
	temp = realloc(result, *reslen + 1); /* result len never includes
						the null byte */
	if (temp == NULL)
	{
		free (result);
		return (-1);
	}

	result = temp;
	result = _strcat(result, &s);

	return (0);
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 * @result:   the output string
 *
 * Return:    0 success, -1 memory allocation failure
 *
 */

int op_string(va_list ap, char *result, int *reslen)
{
	char *s;
	char *temp;
	int s_len;

	s = va_arg(ap, char *);
	if (s)
		s_len = _strlen(s);
	else
	{
		result = _strcat(result, "(null)");
		*reslen = *reslen + 4; /* (null) len six, %s two, diff four */
		return (0);
	}

	if (s_len != 2) /* token length is always two right now */
	{
		*reslen = *reslen + (s_len - 2);
		temp = realloc(result, *reslen + 1); /* result len never includes
							the null byte. */
		if (temp == NULL)
		{
			free (result);
			return (-1);
		}
	}

	result = temp;
	result = _strcat(result, s);

	return (0);
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     0 success, -1 memory allocation failure
 *
 */

int op_percent(va_list ap, char *result, int *reslen)
{
	char *temp;

	ap = ap;

	*reslen = *reslen - 1;

	/* the token length is two and the char length is one. */
	/* shorten the memory by one byte */
	temp = realloc(result, *reslen + 1); /* result len never includes
						the null byte */
	if (temp == NULL)
	{
		free (result);
		return (-1);
	}

	result = temp;
	result = _strcat(result, "%");

	return (0);
}

/**
 * op_decimal- a function to return a decimal from a valist
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     0 success, -1 memory allocation failure
 *
 */

int op_decimal(va_list ap, char *result, int *reslen)
{
	char s[] = "x";

	ap = ap;
	*reslen = *reslen;

	result = _strcat(result, s);

	return (0);
}
