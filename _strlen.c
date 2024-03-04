#include "main.h"

/**
 * _strlen-  determine the length of a string
 *
 * @start    the string to find the longness of
 *
 * Return:   the longness of the string
 *
 */

int _strlen(char *start)
{
    int len = 0;
    
    while (start[len] != '\0')
        len++;

    return (len);
}
