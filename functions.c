#include "main.h"

/**
 * op_char - a function to return a character from a valist
 *
 * @ap:      the valist
 *
 * Returns:  a string array of one character
 *
 */

char *op_char(va_list ap)
{
        return(va_arg(ap, char));
}

/**
 * op_string- a function to return a string from a valist
 *
 * @ap:       the va list
 *
 * Return:    a string array of characters
 *
 */

char *op_string(va_list ap)
{
        return(va_arg(ap, char *));
}

/**
 * op_percent- a placeholder function to return a percent
 *
 * @ap:        the va list
 *
 * Return:     a string array of one %
 *
 */

char *op_percent(va_list ap)
{
        return("%");
}

