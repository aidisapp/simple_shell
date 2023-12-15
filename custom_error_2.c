#include "shell.h"

/**
 * handle_exit_num - write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: user's typed argument after the cmd exit
 * @cmd_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void handle_exit_num(char *str, int cmd_n, list_t *env)
{
	int count = 0;
	char *shell_name = get_shell_name(env), *num = NULL;

	while (shell_name[count] != '\0')
		count++;

	print_string(shell_name, count);
	custom_print(": ");
	num = int_to_string(cmd_n);
	count = 0;

	while (num[count] != '\0')
		count++;

	print_string(num, count);
	custom_print(": ");
	custom_print("exit: Illegal number: ");
	count = 0;

	while (str[count] != '\0')
		count++;

	print_string(str, count);
	custom_print("\n");

	free(shell_name);
	free(num);
}

