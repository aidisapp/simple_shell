#include "shell.h"

/**
 * prompt - Function to display prompt for user input
 */
void prompt(void)
{
	custom_print("simple_shell_$ ");
}

/**
 * read_input_cmd - Function to read the user input
 * @command: the command to read
 * @size: size of the input command
 */
void read_input_cmd(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			custom_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			custom_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}

/**
 * exec_cmd - Function to read the user input
 * @command: the command to read
 * args[arg_count] = NULL - Null-terminate the arguments array
 * execvp(args[0], args) - Execute the command
 */
void exec_cmd(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		custom_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[110];
		int arg_count = 0;

		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

		custom_print("Error executing command.\n");
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
	char command[130];

	while (1)
	{
		prompt();
		read_input_cmd(command, sizeof(command));
		exec_cmd(command);
	}

	return (0);
}

