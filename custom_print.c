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

