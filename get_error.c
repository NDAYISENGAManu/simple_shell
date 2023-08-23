#include "shell.h"

/**
 *_eputs - prints an input string
 * @st: the string to be printed
 * Return: Nothing
 */
void _eputs(char *st)
{
	int j = 0;

	if (!st)
		return;
	while (st[j] != '\0')
	{
		_eputchar(st[j]);
		j++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @m: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char m)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (m == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (m != BUF_FLUSH)
		buff[i++] = m;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @f: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int f)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(f, buff, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @st: the string to be printed
 * @f: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *st, int f)
{
	int i = 0;

	if (!st)
		return (0);
	while (*st)
	{
		i += _putfd(*st++, f);
	}
	return (i);
}

