#include "main.h"

/**
 * get_printf_function- find which function to use for a token
 *
 * @token:              the token to match
 *
 * Return:              the function to execute or NULL if error
 *
 */

int (*get_printf_function(char token))(va_list, int *)
{
	int i = 0;
	op_t ops[] = {
		{'c', op_char}, {'s', op_string}, {'%', op_percent},
		{'d', op_decimal}, {'i', op_decimal}, {'R', op_rotate},
		{'\0', NULL}
	};

	while (ops[i].op)
	{
		if (ops[i].op == token)
			return (ops[i].f);

		i++;
	}
	write(1, &"%", 1);
	write(1, &token, 1);
	return (NULL);
}
