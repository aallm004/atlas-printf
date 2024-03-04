#include "main.h"

/**
 * op_char- a function to return a character from a valist
 *
 * @ap:     the valist
 * @result: the output string
 *
 * Return:  0 success, -1 memory allocation failure
 *
 */

int op_char(va_list ap, char *result, int *reslen)
{
        char s;

        s = va_arg(ap, int);

        result = realloc(result, (*reslen));
        if (!result)
                return (-1);

        /* char is one byte less than token %c */
        *reslen = *reslen - 1;
        result = _strcatc(result, s);

        return (0);
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 * @result:   the output string
 *
 * Return:    0 success, -1 memory allocation failure
 *
 */

int op_string(va_list ap, char *result, int *reslen)
{
        char *s;
        char *temp;
        int s_len;

        s = va_arg(ap, char *);
        if (s)
                s_len = _strlen(s);
        else
        {
                result = _strcat(result, "(null)");
                /* len of '(null)' six, len of '%s' two, difference +four */
                *reslen = *reslen + 4;
                return (0);
        }

        if (s_len != 2) /* token length is always two right now */
        {
                *reslen = *reslen + (s_len - 2);
                /* resut len never includes the null byte, add one */
                temp = realloc(result, *reslen + 1);
                if (temp == NULL)
                {
                        free (result);
                        return (-1);
                }
        }

        result = temp;
        result = _strcat(result, s);

        return (0);
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     0 success, -1 memory allocation failure
 *
 */

int op_percent(va_list ap, char *result, int *reslen)
{
        char *temp;

        ap = ap;

        /* the token length is two and '%' length is one. */
        /* shorten the memory by one byte */
        *reslen = *reslen - 1;

        /* resut len never includes the null byte, add one */
        temp = realloc(result, *reslen + 1);
        if (temp == NULL)
        {
                free (result);
                return (-1);
        }

        result = temp;
        result = _strcat(result, "%");

        return (0);
}

/**
 * op_decimal- a function to return a decimal from a valist
 *
 * @ap:        the va list
 * @result:    the output string
 *
 * Return:     0 success, -1 memory allocation failure
 *
 */

int op_decimal(va_list ap, char *result, int *reslen)
{
        char s[] = "x";

        ap = ap;
        *reslen = *reslen;

        result = _strcat(result, s);

        return (0);
}

/**
 * _op_nothing- handle percent followed by null
 *
 * @ap:         the va list
 * @result:     pointer to result
 * @reslen:     pointer to length of result
 *
 * Return:      0 for success, -1 for memory allocation failure
 *
 */

int op_nothing(va_list ap, char *result, int *reslen)
{
	/* %\0 isn't supported by printf, return -1 */
        ap = ap;
        *reslen = *reslen;
	free(result);

	return (-1);
}
