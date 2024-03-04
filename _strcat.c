/**
 * _strcat - write a function that concatenates two stings
 * @dest : destination
 * @src : string
 *
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int a = 0, b = 0;

	while (*dest)
	{
		dest++;
		a++;
	}

	while (*src)
	{
		*dest = *src;
		dest++;
		a++;
		src++;
		b++;
	}
	*dest = '\0';
	dest = (dest - a);

	return (dest);
}

/**
 * _strcatc- a function that concatenates a char to a string
 *
 * @dest:    the string
 * @src:     the char
 *
 * Return:   dest pointer
 *
 */

char *_strcatc(char *dest, char src)
{
	int a = 0;

	while (*dest)
	{
		dest++;
		a++;
	}

	*dest = src;
	dest++;
	a++;

	*dest = '\0';
	dest = (dest - a);

	return (dest);
}
