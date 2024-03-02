#include "main.h"

/**
 * _strncatconst- concatenate (combine) two strings into one
 *
 * @dest:         the beginning of the string to add to
 * @src:          the source to add the the destination
 * @n:            the maximum number of characters to copy from src
 *
 * Return:        a pointer to dest
 *
 */

char *_strncatconst(char *dest, const char *src, int n)
{
	int d = 0; /* keep track of how far into dest we move */
	int s = 0; /* keep track of how far into src we move */
	int nn = 1; /* counter to n */

	while (*dest)
	{
		dest++;
		d--;
	}

	while (*src && (nn <= n))
	{
		*dest = *src;
		src++;
		dest++;
		d--;
		s--;
		nn++;
	}

	dest += d; /* put things back where we found them.*/
	src += s;
	return (dest);

}
