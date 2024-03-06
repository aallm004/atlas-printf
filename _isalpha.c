/**
 * _isalpha - tells if an ascii is a letter or not
 *
 * @c: a letter or something.
 *
 * Return: 1 if a letter
 *         0 not a letter
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);

	return (0);
}
