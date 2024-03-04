#include <stdio.h>

/**
 * _itoa-  converts int to a char string
 *
 * @num:   integer to be converted
 *
 * Return: pointer to string
 */

char *_itoa(long num)
{
	char neg = ' ';
	char array[10];
	char *result;
	int i = 9;

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
