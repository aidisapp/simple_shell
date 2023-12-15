#include "shell.h"

/**
 * trim_space - Function for trimming spaces
 * @str: string to trim spaces from
 *
 * Return: string without spaces in front
 */
char *trim_space(char *str)
{
	for (; *str == ' '; str++)
		;
	return (str);
}

/**
 * is_valid_digit - Check whether the given digit is a valid digit
 * @c: The digit to be checked
 *
 * Return: 1 on success, 0 on failure
 */
bool is_valid_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * convert_to_digit - Convert a digit to character to digit
 * @c: The digit to be checked
 *
 * Return: 1 on success, 0 on failure
 */
int convert_to_digit(char c)
{
	return (c - '0');
}

/**
 * string_to_int - Converts a string representing a number to an integer
 * @str: The string to convert
 *
 * Return: 1 on success, 0 on failure
 */
int string_to_int(char *str)
{
	int index = 0;
	int number = 0;

	while (str[index] != '\0')
	{
		if (is_valid_digit(str[index]))
			number = number * 10 + convert_to_digit(str[index]);
		else
			return (-1);

		index++;
	}

	return (number);
}

/**
 * exit_program - Exits shell with provided status
 * @args: command arguments
 * @env_v: List of environment variables
 * @cmd_num: Current command line number
 * @cmd: Command to free
 *
 * Return: 0 if success 2 if fail
 */
int exit_program(char **args, list_t *env_v, int cmd_num, char **cmd)
{
	int e_value = 0;

	if (args[1] != NULL)
		e_value = string_to_int(args[1]);

	if (e_value == -1)
	{
		illegal_number(args[1], cmd_num, env_v);
		free_double_ptr(args);
		return (2);
	}

	free_double_ptr(args);
	free_linked_list(env_v);

	if (cmd != NULL)
		free_double_ptr(cmd);

	exit(e_value);
}

