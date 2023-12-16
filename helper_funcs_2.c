#include "shell.h"

/**
 * handle_builtin - handles the builtins functions
 * Functions such as; exit, env, cd
 * @args: Arguments
 * @env: Environment variable
 * @line_num: Line number
 * @cmd: Command line argument to free
 *
 * Return: 1 on success, 0 on failure
 */
int handle_builtin(char **args, list_t *env, int line_num, char **cmd)
{
	int result = 0;

	if (_strcmp(args[0], "setenv") == 0)
	{
		_setenv(&env, args);
		result = 1;
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		unset_env(&env, args);
		result = 1;
	}
	else if (_strcmp(args[0], "exit") == 0)
		result = exit_program(args, env, line_num, cmd);
	else if (_strcmp(args[0], "env") == 0)
	{
		custom_env(args, env);
		result = 1;
	}
	else if (_strcmp(args[0], "cd") == 0)
		result = exec_cd(args, env, line_num);

	return (result);
}

/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len_1, len_2, total = 0, count;

	for (len_1 = 0; dest[len_1] != '\0'; len_1++)
		total++;

	for (len_2 = 0; src[len_2] != '\0'; len_2++)
		total++;

	dest = mem_alloc(dest, len_1, sizeof(char) * total + 1);

	for (count = 0; src[count] != '\0'; count++, len_1++)
		dest[len_1] = src[count];

	dest[len_1] = '\0';
	return (dest);
}

/**
 * custom_setenv - custom environment setting by concatenating
 * string first before setting
 * @env_list: environmental variable linked list
 * @var_name: environmental variable name
 * @path: directory
 *
 * Return: 0 on success
 */
int custom_setenv(list_t **env_list, char *var_name, char *path)
{
	list_t *node;
	char *concat_str;
	int idx;

	concat_str = _strdup(var_name);
	concat_str = _strcat(concat_str, "=");
	concat_str = _strcat(concat_str, path);
	idx = find_env_list(*env_list, var_name);
	node = get_node(*env_list, idx);
	free(node->v);
	node->v = _strdup(concat_str);
	free(concat_str);

	return (EXIT_SUCCESS);
}

/**
 * get_node - get the node at a given index in a linked list
 * @head: pointer to the head of the list
 * @index: index of the node to get
 * Return: pointer to the node or NULL if not found
 */
list_t *get_node(list_t *head, int index)
{
	int i;

	for (i = 0; i < index && head; i++)
		head = head->next_node;
	return (head);
}

/**
 * change_to_home_directory - change working directory to home directory
 * @env: environmental linked list
 * @current: current working directory
 */
void change_to_home_directory(list_t *env, char *current)
{
	char *home_dir;

	home_dir = fetch_env_v("HOME", env);
	custom_setenv(&env, "OLDPWD", current);
	free(current);
	chdir(home_dir);
	current = getcwd(NULL, 0);
	custom_setenv(&env, "PWD", current);
	free(current);
	free(home_dir);
}

