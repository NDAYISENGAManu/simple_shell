#include "shell.h"
/**
 *_myenv - get the environment
 *@data: the string to be parsed
 *Return: (0)
 */
int _myenv(info_t *data)
{
	print_list_str(data->env);
	return (0);
}

/**
 **_getenv - get the environment
 *@data: the string to be parsed
 *Return: (Null)
 */
char *_getenv(info_t *data, const char *name)
{
	list_t *node = data->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 *_mysetenv - set the environment
 *@data: the string to be parsed
 *Return: (Null)
 */
int _mysetenv(info_t *data)
{
	if (data->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(data, data->argv[1], data->argv[2]))
		return (0);
	return (1);
}

/**
 *_mysetenv - set the environment
 *@data: the string to be parsed
 *Return: (Null)
 */
int _myunsetenv(info_t *data)
{
	int i;

	if (data->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		_unsetenv(data, data->argv[i]);

	return (0);
}

/**
 *_mysetenv - set the environment
 *@data: the string to be parsed
 *Return: (Null)
 */
int populate_env_list(info_t *data)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	data->env = node;
	return (0);
}

