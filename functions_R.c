#include "main.h"

/**
 * op_rotate- rot13 a string
 *
 * @ap:       the va list
 * @reslen:   a pointer to the length of the result
 *
 * Return:    0 success
 *
 */

int op_rotate(va_list ap, int *reslen)
{
	char *s;
	int s_len;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";

	s = rot13_string(s);
	s_len = _strlen(s);

	*reslen = *reslen + (s_len - 2);

	write(1, s, s_len);

	return (0);
}

/**
 * rot13_string-  a function to apply the rot13 cypher to a string
 *
 * @s:            the string to rot13
 *
 * Return:        the encoded/decoded string
 *
 */

char *rot13_string(char *s)
{
	int i, len = 0;

	len = _strlen(s);

	for (i = 0; i < len; i++)
	{
		s[i] = rot13_char(s[i]);
	}

	return (s);
}

/**
 * rot13_char- a function to apply the rot13 cypher to one character
 *
 * @c:         the charcater to rot13
 *
 * Return:     the endcoded/decoded character
 *
 */

char rot13_char(char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		return (c + 13);
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		return (c - 13);
	else
		return (c);
}
