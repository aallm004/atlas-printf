/**
 * _strlenconst - returns the length of a string
 *
 * @s:            a constant string pointer
 *
 * Return:        the length of the string
 */

int _strlenconst(const char *s)
{
        int x;

        x = 0;

        while (s[x] != '\0')
        {
                x++;
        }

        return (x);
}
