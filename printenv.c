#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @data: Struct containing arguments with used to maintain constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *data)
{
	if (!data->environ || data->env_changed)
	{
		data->environ = list_to_strings(data->env);
		data->env_changed = 0;
	}

	return (data->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @data: Struct containing arguments with used to maintain constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @va: the string env var property
 */
int _unsetenv(info_t *data, char *va)
{
	list_t *node = data->env;
	size_t i = 0;
	char *p;

	if (!node || !va)
		return (0);

	while (node)
	{
		p = starts_with(node->str, va);
		if (p && *p == '=')
		{
			data->env_changed = delete_node_at_index(&(data->env), i);
			i = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (data->env_changed);
}

/**
 * _setenv - Initialize a new environment variable or modify an existing one
 * @data: Struct containing arguments with used to maintain constant function prototype.
 * @va: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *data, char *va, char *val)
{
	char *buff = NULL;
	list_t *node;
	char *p;

	if (!va || !val)
		return (0);

	buff = malloc(_strlen(va) + _strlen(val) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, va);
	_strcat(buff, "=");
	_strcat(buff, val);
	node = data->env;
	while (node)
	{
		p = starts_with(node->str, va);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buff;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(data->env), buff, 0);
	free(buff);
	data->env_changed = 1;
	return (0);
}
