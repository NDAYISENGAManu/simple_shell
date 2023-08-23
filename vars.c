#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @data: parameter struct
 * @buff: the char buffer
 * @po: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *data, char *buff, size_t *po)
{
	size_t j = *po;

	if (buff[j] == '|' && buff[j + 1] == '|')
	{
		buff[j] = 0;
		j++;
		info->cmd_buff_type = CMD_OR;
	}
	else if (buff[j] == '&' && buff[j + 1] == '&')
	{
		buff[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buff[j] == ';') /* found end of this command */
	{
		buff[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*po = j;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @data: the parameter struct
 * @buff: the char buffer
 * @po: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *data, char *buff, size_t *po, size_t i, size_t len)
{
	size_t j = *po;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buff[i] = 0;
			j = len;
		}
	}

	*po = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *po;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		po = _strchr(node->str, '=');
		if (!po)
		{
			return (0);
		}
		po = _strdup(p + 1);
		if (!p)
		{
			return (0);
		}
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @data: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *data)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
		{
			continue;
		}

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			{
				continue;
			}
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			{
				continue;
			}
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			{
				continue;
			}
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
