#include "shell.h"

/**
* _strcmp - a function that compares two strings
* @str1: first string
* @str2: second string
* Return: int that tells num spaces in between
*/

int _strcmp(char *str1, char *str2)
{
int count = 0;

while (*(str1 + count) == *(str2 + count) && *(str1 + count))
	count++;

if (*(str2 + count))
	return (*(str1 + count) - *(str2 + count));
else
	return (0);
}

/**
* _strcpy - a function that copies string pointed to by source
* @dest: destination to copy strings to
* @src: source is the string to copy
*
* Return: returns the pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
int count = 0, length = 0;

while (src[length] != '\0')
	length++;

while (count <= length)
{
	dest[count] = src[count];
	count++;
}

return (dest);
}

/**
* _strdup - Duplicate string
* @str: string to duplicate from
* Return: length of token
*/
char *_strdup(char *str)
{
	char *dup_str;
	int count, length = 0;

	if (str == NULL)
		return (NULL);

	for (length = 0; *(str + length) != '\0'; length++)
		;
	length++;

	dup_str = malloc(sizeof(char) * length);
	if (dup_str == NULL)
		return (NULL);

	for (count = 0; count < length; count++)
		*(dup_str + count) = *(str + count);

	return (dup_str);
}

/**
* t_strlen - calculates length of a token from user input
* @token: token string
* @index: current position index in user input
* @delimiter: character delimiting tokens
* Return: length of token
*/
int t_strlen(char *token, int index, char delimiter)
{
int length = 0;

for (;
	token[index] != delimiter && token[index] != '\0';
	index++, length++)
	;

return (length);
}

/**
 * match_path - Function to append command to a matching PATH pathectory
 * @command: first command
 * @env_vars: environmental variables list
 *
 * Return: return a copy of appended command
 */
char *match_path(char *command, list_t *env_vars)
{
	char *path, *dir = NULL, **tokens;
	int count;

	path = fetch_env_v("PATH", env_vars);
	tokens = cont_delim(path, ":");
	free(path);

	for (count = 0; tokens[count] != NULL; count++)
	{
		if (tokens[count][0] == '\0')
			dir = getcwd(dir, 0);
		else
			dir = _strdup(tokens[count]);

		dir = _strcat(dir, "/");
		dir = _strcat(dir, command);

		if (access(dir, F_OK) == 0)
		{
			free_pointer(tokens);
			return (dir);
		}

		free(dir);
	}

	free_pointer(tokens);
	return (command);
}

