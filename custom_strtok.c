#include "shell.h"

/**
* delim_n - function that returns the number of delimiters
* @str: user's command typed into shell
* @delim: delimiter
*
* Return: number of delimiters for the custom strtok function
*/
int delim_n(char *str, char delim)
{
int count, delim_num = 0;

for (count = 0; str[count] != '\0'; count++)
{
	if ((str[count] == delim) && (str[count + 1] != delim))
	delim_num++;

	if ((str[count] == delim) && (str[count + 1] == '\0'))
	delim_num--;
}
return (delim_num);
}

/**
* ignore_delimeter - Function that returns string without preceeding delimeters
* @str: string
* @delimeter: delimiter
*
* Return: new string
*/
char *ignore_delimeter(char *str, char delimeter)
{
while (*str == delimeter)
	str++;

return (str);
}

/**
* custom_strtok - function that tokenizes a string
* and returns an array of tokens
* @str: user's command typed into shell
* @delim: delimeter
*
* Return: an array of tokens
*/
char **custom_strtok(char *str, char *delim)
{
	int buf = 0, tok_i = 0, str_i = 0, count = 0, len = 0, se = 0, tok_c = 0;
	char **toks = NULL, d_ch;

	d_ch = delim[0];
	str = ignore_delimeter(str, d_ch);
	buf = delim_n(str, d_ch);
	toks = malloc(sizeof(char *) * (buf + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')
		se++;
	while (str_i < se)
	{
		if (str[str_i] != d_ch)
		{
			len = t_strlen(str, str_i, d_ch);
			toks[tok_i] = malloc(sizeof(char) * (len + 1));
			if (toks[tok_i] == NULL)
				return (NULL);
			count = 0;
			while ((str[str_i] != d_ch) && (str[str_i] != '\0'))
			{
				toks[tok_i][count] = str[str_i];
				count++;
				str_i++;
			}
			toks[tok_i][count] = '\0';
			tok_c++;
		}

		if (str_i < se && (str[str_i + 1] != d_ch && str[str_i + 1] != '\0'))
			tok_i++;
		str_i++;
	}
	tok_i++;
	toks[tok_i] = NULL;
	return (toks);
}

/**
* cont_delim - function that tokenizes a string
* even the continuous delim with empty string
* @str: user's command typed into shell
* @delimeter: delimeter
* Return: an array of tokens
*/
char **cont_delim(char *str, char *delimeter)
{
int buf_size = 0, tok_i = 0, str_i = 0, count = 0, len = 0, str_idx = 0;
char **toks = NULL, d_ch;

d_ch = delimeter[0];
buf_size = delim_n(str, d_ch);
toks = malloc(sizeof(char *) * (buf_size + 2));
if (toks == NULL)
	return (NULL);

while (str[str_idx] != '\0')
	str_idx++;

while (str_i < str_idx)
{
	len = t_strlen(str, str_i, d_ch);
	toks[tok_i] = malloc(sizeof(char) * (len + 1));
	if (toks[tok_i] == NULL)
	return (NULL);
	count = 0;
	while ((str[str_i] != d_ch) &&
		(str[str_i] != '\0'))
	{
	toks[tok_i][count] = str[str_i];
	count++;
	str_i++;
	}
	toks[tok_i][count] = '\0';
	tok_i++;
	str_i++;
}
toks[tok_i] = NULL;
return (toks);
}

