#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@ar: the pointer to the memory area
 *@bi: the byte to fill *s with
 *@am: the amount of bytes to be filled
 *Return: (ar) a pointer to the memory area s
 */
char *_memset(char *ar, char bi, unsigned int am)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		ar[i] = bi;
	return (ar);
}

/**
 * ffree - frees a string of strings
 * @pop: string of strings
 */
void ffree(char **pop)
{
	char **a = po;

	if (!po)
	{
		return;
	}
	while (*po)
	{
		free(*po++);
	}
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @point: pointer to previous malloc'ated block
 * @old: byte size of previous block
 * @new: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *point, unsigned int old, unsigned int new)
{
	char *p;

	if (!point)
	{
		return (malloc(new));
	}
	if (!new)
	{
		return (free(point), NULL);
	}
	if (new == old)
	{
		return (point);
	}
	p = malloc(new);
	if (!p)
	{
		return (NULL);
	}

	old = old < new ? old : new;
	while (old--)
	{
		p[old] = ((char *)point)[old];
	free(ptr);
	return (p);
}
