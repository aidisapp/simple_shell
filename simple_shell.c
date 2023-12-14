#include "shell.h"

/**
 * prompt - Function to read the user input
 *
 * Return: the number of characters read
 */
void prompt(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	custom_print("$ ");
}

/**
 * handle_command - Function to read the user input
 * @input: Command to execute
 *
 * Return: the number of characters read
 */
void handle_command(char *input)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char **argv = malloc(2 * sizeof(char *));

		argv[0] = input;
		argv[1] = NULL;

		if (execve(input, argv, environ) == -1)
		{
			custom_print("./hsh: No such file or directory\n");
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("fork");
	else
		waitpid(pid, NULL, 0);
}

/**
 * main - Main entry point
 * This function is the main function of the shell application
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		prompt();

		if (!fgets(input, MAX_INPUT_SIZE, stdin))
			break;

		handle_command(input);
	}

	return (0);
}

