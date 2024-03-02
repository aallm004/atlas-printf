#include "main.h"
#include <stdbool.h>

/**
 * _strcpy-  copy a string
 *
 * @dest:    where to put the copy
 * @src:     what to copy
 *
 * Return:   pointer to @dest
 */

char *_strcpy(char *dest, char *src)
{
	int position = 0;
	bool exit = 0;

	while (!exit)
	{
		dest[position] = src[position];
		if (src[position] == 0)
			exit = true;
		position++;
	}

	return (dest);
}
