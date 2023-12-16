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
 * @len: length of string
 */
void print_string(char *str, int len)
{
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
	return (fetch_env_v("_", env));
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

	custom_print(shell_name);
	custom_print(": ");

	custom_print(cmd_num_str);
	custom_print(": ");

	custom_print(cmd);
	custom_print(": not found\n");

	free(shell_name);
	free(cmd_num_str);
}

/**
 * handle_cd_error - Prints error message for failed cd command
 * @dir: Invalid directory path attempted
 * @cmd_count: Current command count
 * @env: Environment vars list
 */
void handle_cd_error(char *dir, int cmd_count, list_t *env)
{
	int count = 0;
	char *shell_name = get_shell_name(env), *num;

	while (shell_name[count] != '\0')
		count++;

	print_string(shell_name, count);
	free(shell_name);
	custom_print(": ");
	num = int_to_string(cmd_count);
	count = 0;

	while (num[count] != '\0')
		count++;

	print_string(num, count);
	free(num);
	custom_print(": ");
	custom_print("cd: can't cd to ");
	count = 0;

	while (dir[count] != '\0')
		count++;

	print_string(dir, count);
	custom_print("\n");
}

