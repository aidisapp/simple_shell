#include "shell.h"

/**
 * custom_print - writes the str to stdout
 * @str: the parameter that will be printed out
 *
 * Return: 0 on success
 */
int custom_print(char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}

/**
 * print_string - write error not found message
 * @str: command input string
 */
void print_string(char *str)
{
	int len = strlen(str);

	write(STDOUT_FILENO, str, len);
}

/**
 * get_shell_name - Get the name of the shell
 * @env: command input string
 *
 * Return: the name of the shell
 */
char *get_shell_name(list_t *env)
{
	return (get_env("_", env));
}

/**
 * err_not_found - write error not found message
 * @cmd: command input string
 * @line_num: nth entered command
 * @env_list: environmental variables linked list
 */
void err_not_found(char *cmd, int line_num, list_t *env_list)
{
	char *shell_name = get_shell_name(env_list);
	char *cmd_num_str = int_to_string(line_num);

	print_string(shell_name);
	print_string(": ");

	print_string(cmd_num_str);
	print_string(": ");

	print_string(cmd);
	print_string(": not found\n");

	free(shell_name);
	free(cmd_num_str);
}

