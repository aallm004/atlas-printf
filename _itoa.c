#include <stdio.h>
#include <limits.h>

/**
 * _itoa-  converts int to a char string
 *
 * @num:   integer to be converted
 *
 * Return: pointer to string
 */

char *_itoa(int num)
{
	char array[11];
	char *result;
	int i = 10;

	if (num == 0)
	{
		array[i--] = '0';
		result = array + i + 1;
		return (result);
	}

	if (num > 0)
	{
		while (num)
		{
			array[i--] = '0' + (num % 10);
			num = num / 10;
		}
	}
	else
	{
		while (num)
		{
			array[i--] = '0' - (num % 10);
			num = num / 10;
		}
		array[i--] = '-';
	}

	result = array + i + 1;
	return (result);
}
