#include "shell.h"

/**
 * find_env_list - FUnction to find environmental variable in linked list given
 * @env_list: environmental variable linked list
 * @str: atring to search
 *
 * Return: index of node in linked list
 */
int find_env_list(list_t *env_list, char *str)
{
	int count_1, count_2;

	for (count_1 = 0; env_list != NULL; count_1++)
	{
		count_2 = 0;
		while ((env_list->v)[count_2] == str[count_2])
			count_2++;

		if (str[count_2] == '\0')
			break;

		env_list = env_list->next_node;
	}
	if (env_list == NULL)
		return (-1);

	return (count_1);
}

/**
 * _setenv - Function to set environmental variable
 * create or modify existing environmental variable in linked list
 * @env_list: environmental variable linked list
 * @cmd: typed in command to be executed
 *
 * Return: return 0 on success, 1 on failure
 */
int _setenv(list_t **env_list, char **cmd)
{
	int find_i = 0, count;
	char *str;
	list_t *temp;

	if (cmd[1] == NULL || cmd[2] == NULL)
	{
		custom_print("Too few arguments\n");
		free_pointer(cmd);
		return (-1);
	}

	str = _strdup(cmd[1]);
	str = _strcat(str, "=");
	str = _strcat(str, cmd[2]);
	find_i = find_env_list(*env_list, cmd[1]);

	if (find_i == -1)
		add_list_end(env_list, str);
	else
	{
		temp = *env_list;
		for (count = 0; count < find_i; count++)
			temp = temp->next_node;

		free(temp->v);
		temp->v = _strdup(str);
	}

	free(str);
	free_pointer(cmd);
	return (0);
}

/**
 * unset_env - Function to unset env variable
 * remove node in environmental linked list
 * @env_list: environmental linked list
 * @str: user's typed in command
 *
 * Return: 0 on success
 */
int unset_env(list_t **env_list, char **str)
{
	int list_idx = 0, del_list = 0;

	if (str[1] == NULL)
	{
		custom_print("Too few arguments\n");
		free_pointer(str);
		return (-1);
	}

	list_idx = find_env_list(*env_list, str[1]);
	free_pointer(str);
	if (list_idx == -1)
	{
		custom_print("Cannot find\n");
		return (-1);
	}

	del_list = delete_list_idx(env_list, list_idx);
	if (del_list == -1)
	{
		custom_print("Cannot find\n");
		return (-1);
	}

	return (EXIT_SUCCESS);
}

