#include "shell.h"

/**
 * exit_shell - frees user command buffer and env variable list before exiting
 * @user_command: pointer to user entered command string
 * @env_vars: pointer to linked list of environment variables
 */
void exit_shell(char **user_command, list_t *env_vars)
{
	free_pointer(user_command);
	free_list(env_vars);
	_exit(0);
}

/**
 * exec_proc - executes a command in a child process
 * @cmd_path: path to the command to execute
 * @cmd: command to execute
 * @env_vars: environmental variables
 * @cmd_num: nth user command; to be used in error message
 */
void exec_proc(char *cmd_path, char **cmd, list_t *env_vars, int cmd_num)
{
	if (execve(cmd_path, cmd, NULL) == -1)
	{
		err_not_found(cmd[0], cmd_num, env_vars);
		exit_shell(cmd, env_vars);
	}
}

/**
 * custom_exec - execute command user typed into shell
 * @user_cmd: command user typed
 * @env_vars: environmental variable
 * @cmd_num: nth user command; to be used in error message
 * Return: 0 on success
 */
int custom_exec(char **user_cmd, list_t *env_vars, int cmd_num)
{
	char *exec_path;
	int exec_status = 0, found = 0;
	pid_t child_pid;

	if (access(user_cmd[0], F_OK) == 0)
	{
		exec_path = user_cmd[0];
		found = 1;
	}
	else
	{
		exec_path = match_path(user_cmd[0], env_vars);
	}

	if (access(exec_path, X_OK) != 0)
	{
		err_not_found(user_cmd[0], cmd_num, env_vars);
		free_pointer(user_cmd);
		return (127);
	}
	else
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			exec_proc(exec_path, user_cmd, env_vars, cmd_num);
		}
		else
		{
			wait(&exec_status);
			free_pointer(user_cmd);
			if (found == 0)
				free(exec_path);
		}
	}

	return (0);
}

