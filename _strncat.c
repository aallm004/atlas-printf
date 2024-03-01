/**
 * _strncat - write a function that concatenates two stings
 * @dest : destination
 * @src : string
 * @n : end
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int a = 0;

	while (*dest)
	{
		dest++;
		a++;
	}

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		a++;
		src++;
		n--;
		if (n == 0)
		{
		break;
		}
	}

	dest = (dest - a);

	return (dest);
}
