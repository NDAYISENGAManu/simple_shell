#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @data: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *data, char *path)
{
	struct stat s;

	(void)data;
	if (!path || stat(path, &s))
	{
		return (0);
	}

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @strt: starting index
 * @stp: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int strt, int stp)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = strt; i < stp; i++)
		if (pathstr[i] != ':')
		{
			buf[k++] = pathstr[i];
		}
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @data: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *data, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
	{
		return (NULL);
	}
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(data, cmd))
		{
			return (cmd);
		}
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
			{
				_strcat(path, cmd);
			}
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(data, path))
			{
				return (path);
			}
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
