#include "main.h"
#include <stdio.h>

/**
 * _strappendconst- copy source string to destination starting at first null
 *                  terminator
 *
 * @dest:           the destionation for the copy
 * @src:            the source to copy into the destination
 * @n:              the maximum number of characters to copy from src to dest
 *
 * Return:    a pointer to dest
 *
 */

char *_strappendconst(char *dest, const char *src, int n)
{
	int d = 0; /* keep track of how far into dest we move */

	while (*dest && (n > 0)) /* move dest ptr fwd until  null found */
	{
		dest++;
		d++; /* keep track of how many we move forward */
		printf("moving forward in dest %s", dest);
	}

	for (; n > 0; n--)
	{
		*dest = *src;
		dest++;
		src++;
		d--;
	}

	dest += d; /* put things back where we found them.*/

	printf("dest is returning with %s", dest);
	return (dest);

}
