#include "shell.h"

/**
* custom_str_dup - Function to duplicate string
* excludes beginning bytes
* @str: string to duplicate
* @bytes_n: number of bytes to exclude from duplicate
*
* Return: duplicated string without beginning bytes
*/
char *custom_str_dup(char *str, int bytes_n)
{
char *dup_str;

int count, length = 0;

if (str == NULL)
	return (NULL);

while (*(str + length))
	length++;

length++;

dup_str = malloc(sizeof(char) * (length - bytes_n));
if (dup_str == NULL)
	return (NULL);

for (count = 0; count < (length - bytes_n); count++)
	*(dup_str + count) = *(str + bytes_n + count);

return (dup_str);
}

/**
* fetch_env_v - Function to find requested env variables
* returns a copy of the requested env variable
* @store_env: variable to store in the environment
* @env_lists: all the environmental variables
*
* Return: The requested environmental variable copies
*/
char *fetch_env_v(char *store_env, list_t *env_lists)
{
int count = 0, bytes_n = 0;

do {
	while ((env_lists->v)[count] == store_env[count])
	count++;

	if (store_env[count] == '\0' && (env_lists->v)[count] == '=')
	break;
	env_lists = env_lists->next_node;
} while (env_lists != NULL);

while (store_env[bytes_n] != '\0')
	bytes_n++;

bytes_n++;
return (custom_str_dup(env_lists->v, bytes_n));
}

/**
* trim_space_alt - Function for trimming spaces and ignore new lines
* @str: string to trim spaces from
*
* Return: string without spaces in front
*/
char *trim_space_alt(char *str)
{
for (; *str == ' ' || *str == '\n'; str++)
	;
return (str);
}

/**
* pipe_commands - Function to handles pipes commands into shell via pipeline
* This function also handles non-interactive commands
* @env_list: envrionmental variable list
*/
void pipe_commands(list_t *env_list)
{
int cmd_line_no = 0, exit_status = 0;
char *cmd = NULL, *cmd_num = NULL, **n_line, **token;

size_t user_line = get_user_line(&cmd), count;

if (user_line == 0)
{
	free(cmd);
	exit(EXIT_SUCCESS);
}
cmd_num = cmd;
cmd = trim_space_alt(cmd);
n_line = custom_strtok(cmd, "\n");
if (cmd_num != NULL)
	free(cmd_num);

for (count = 0; n_line[count] != NULL; count++)
{
	cmd_line_no++;
	token = NULL;
	token = custom_strtok(n_line[count], " ");
	exit_status = handle_builtin(token, env_list, cmd_line_no, n_line);
	if (exit_status)
	{
	count++;
	continue;
	}
	exit_status = custom_exec(token, env_list, cmd_line_no);
}

free_pointer(n_line);
free_list(env_list);
exit(exit_status);
}

