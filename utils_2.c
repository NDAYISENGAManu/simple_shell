#include "shell.h"

/**
 * _strcpy - copies a string
 * @destin: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *destin, char *src)
{
	int i = 0;

	if (destin == src || src == 0)
	{
		return (destin);
	}
	while (src[i])
	{
		destin[i] = src[i];
		i++;
	}
	destin[i] = 0;
	return (destin);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rt;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		length++;
	}
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
	{
		return (NULL);
	}
	for (length++; length--;)
	{
		rt[length] = *--str;
	}
	return (rt);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
	{
		return;
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
	{
		buf[i++] = ch;
	}
	return (1);
}
