#include <stdio.h>

/**
 * itoa - converts int to a char string
 *
 * @i: integer to be converted
 *
 * Return:
 */

char *_itoa(int num)
{
	char neg = ' ';
	char array[11];
	char *result;
	int i = 10;

	if (num < 0)
	{
		num *= -1;
		neg = '-';
	}

	if (num == 0)
	{
		array[i--] = '0';
		result = array + i + 1;
		return (result);
	}

	while (num)
	{
		array[i--] = (num % 10) + '0';
		num = num / 10;
	}

	if (neg == '-') 
		array[i--] = neg;

	result = array + i + 1;

	return (result);
}
