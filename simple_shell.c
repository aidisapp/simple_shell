#include "shell.h"

/**
 * read_input_cmd - Function to read the user input
 * @cmd: the command to read
 * @size: size of the input command
 */
void read_input_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			custom_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			custom_print("Error while reading command.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0';
}

/**
 * exec_cmd - Function to read the user input
 * @cmd: the command to read
 * args[arg_count] = NULL - Null-terminate the arguments array
 * execvp(args[0], args) - Execute the command
 * custom_print("Error executing command");
 */
void exec_cmd(const char *cmd)
{
	pid_t child_pid = fork();
	char *args[110], *token;
	int arg_count = 0;

	if (child_pid == -1)
	{
		custom_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		token = strtok((char *)cmd, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

		write(2, "./hsh: 1: ", 10);
		write(2, args[0], strlen(args[0]));
		write(2, ": not found", 11);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Main entry point
 * This function is the main function of the shell application
 *
 * Return: o on success, -1 on failure
 */
int main(void)
{
	char input_cmd[110];

	while (1)
	{
		if (isatty(STDIN_FILENO == 1))
		custom_print("# ");

		read_input_cmd(input_cmd, sizeof(input_cmd));
		exec_cmd(input_cmd);
	}

	return (0);
}

