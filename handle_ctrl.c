#include "shell.h"

/**
* handle_ctrl_c - ignore Ctrl-C input and prints prompt again
* @c: command line to ignore
*/
void handle_ctrl_c(int c)
{
	(void)c;
	custom_print("\n$ ");
}

/**
* handle_ctrl_d - exits program
* @arg: command line
* @cmd: command line arguments
* @env: environmental variable linked list (list_t)
*/
void handle_ctrl_d(int arg, char *cmd, list_t *env)
{
	if (arg == 0)
	{
		free(cmd);
		free_linked_list(env);

		if (isatty(STDIN_FILENO))
			custom_print("\n");

		exit(EXIT_SUCCESS);
	}
}

