#include "shell.h"

/**
* linked_list - Function that creates a linked list
* The list is created from environmental variables
* @env_list: environmental variables
*
* Return: linked list
*/
list_t *linked_list(char **env_list)
{
list_t *head_node;
int count;

head_node = NULL;

for (count = 0; env_list[count] != NULL; count++)
	add_list_end(&head_node, env_list[count]);

return (head_node);
}

/**
* custom_env - Function that prints environmental variables
* @cmd: command
* @env_list: environmental variable list
*
* Return: 0 on success
*/
int custom_env(char **cmd, list_t *env_list)
{
free_pointer(cmd);
print_linked_list(env_list);

return (EXIT_SUCCESS);
}

/**
* free_pointer - Function that frees dynamic malloced array pointers
* @str: array of strings to free
*/
void free_pointer(char **str)
{
int count;

for (count = 0; str[count] != NULL; count++)
	free(str[count]);

free(str);
}

/**
 * num_length - Function to counts number of zeros in a tens square number
 * @arg: number to count
 * Return: returns count of digits
 */
int num_length(int arg)
{
	int count = 0, num = arg;

	for (count = 0; num > 9 || num < -9; count++)
		num /= 10;

	return (count);
}

/**
 * int_to_string - turns an int into a string
 * @num: number to convert
 * Return: returns the int as a string
 */

char *int_to_string(int num)
{
	int digits = num, tens = 1, count = 0, t_count = 0, val;
	char *result;

	if (num < 0)
		t_count = 1;
	result = malloc(sizeof(char) * (num_length(digits) + 2 + t_count));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		result[count] = '-';
		count++;
	}
	for (val = 0; digits > 9 || digits < -9; val++)
	{
		digits /= 10;
		tens *= 10;
	}
	for (digits = num; val >= 0; val--)
	{
		if (digits < 0)
		{
			result[count] = (digits / tens) * -1 + '0';
			count++;
		}
		else
		{
			result[count] = (digits / tens) + '0';
			count++;
		}
		digits %= tens;
		tens /= 10;
	}
	result[count] = '\0';
	return (result);
}

