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

