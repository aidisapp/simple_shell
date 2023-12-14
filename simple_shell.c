#include "shell.h"

/**
 * execute_cmd - function that executes the command
 * Display prompts for user
 * @token: command token
 * @env: Environment
 * @cmd_line_num: number of arguments
 *
 * Return: 0 if successful
 */
int execute_cmd(char **token, list_t *env, int cmd_line_num)
{
	int exit_stat = 0;

	exit_stat = handle_builtin(token, env, cmd_line_num, NULL);

	if (exit_stat)
		return (exit_stat);

	exit_stat = _execve(token, env, cmd_line_num);
	return (exit_stat);
}

/**
 * process_cmd - function to process command
 * @cmd: Environment
 * @env: Command to execute
 * @cmd_line_num: Number of arguments
 *
 * Return: 0 on success
 */
int process_cmd(char *cmd, list_t *env, int cmd_line_num)
{
	char *n_command, **token;
	int exit_stat = 0, n = 0;

	n_command = cmd;
	cmd = trim_space(cmd);
	n = 0;

	while (cmd[n] != '\n')
		n++;

	cmd[n] = '\0';
	if (cmd[0] == '\0')
	{
		free(n_command);
		return (exit_stat);
	}

	token = NULL;
	token = _str_tok(cmd, " ");

	if (n_command != NULL)
		free(n_command);

	exit_stat = execute_cmd(token, env, cmd_line_num);
	return (exit_stat);
}

/**
 * display_prompt - function to display prompt
 * Display prompts for user and executes commands when given
 * @arg_env: envrionmental variables
 * Return: 0 on success
 */
int display_prompt(char **arg_env)
{
	list_t *env = env_linked_list(arg_env);
	size_t count = 0;
	int cmd_line_num = 0, exit_stat = 0;
	char *cmd;

	while (true)
	{
		cmd_line_num++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);

		signal(SIGINT, ctrl_c);
		cmd = NULL;
		count = get_line(&cmd);
		ctrl_D(count, cmd, env);
		exit_stat = process_cmd(cmd, env, cmd_line_num);
	}

	return (exit_stat);
}

/**
 * main - creates a simple shell
 * @argc: argument count
 * @argv: argument vectors
 * @env: environmental variables
 * Return: 0 on success
 */
int main(int argc, char *argv[], char **env)
{
	(void)argc;
	(void)argv;

	display_prompt(env);

	return (0);
}

