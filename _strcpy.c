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

/**
 * _strlen-  determine the length of a string
 *
 * @s:       the string to find the longness of
 *
 * Return:   the longness of the string
 *
 */

int _strlen(char *s)
{
	int pos = 0;

	while (s[pos] != 0)
		pos++;

	return (pos);
}
