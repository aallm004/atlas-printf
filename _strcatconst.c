/**
 * _strcatconst- a function that concatenates two stings
 *
 * @dest : destination
 * @src : string
 *
 * Return: dest
 */

char *_strcatconst(char *dest, const char *src)
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
