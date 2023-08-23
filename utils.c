#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
	{
		return (0);
	}
	while (*str++)
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @str1: string one
 * @str2: string two
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}

/**
 * starts_with - checks if find starts with search
 * @search: string to search
 * @find: the substring to find
 *
 * Return: address of next char of search or NULL
 */
char *starts_with(const char *search, const char *find)
{
	while (*find)
	{
		if (*find++ != *search++)
		{
			return (NULL);
		}
	return ((char *)search);
}

/**
 * _strcat - concatenates two strings
 * @destin: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destin, char *src)
{
	char *rt = destin;

	while (*destin)
	{
		destin++;
	}
	while (*src)
	{
		*destin++ = *src++;
	}
	*destin = *src;
	return (rt);
}
