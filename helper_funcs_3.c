#include "shell.h"

/**
 * change_dir - changes the current directory
 * @env_list: the linked list of environment variables
 * @cur_dir: the current working directory
 * @new_dir: the new directory path to change to
 * @arg: the first argument to print out error
 * @line: the line number to print out error
 *
 * Return: 0 if success, 2 if fail
 */
int change_dir(list_t *env_list, char *cur_dir, char *new_dir,
							 char *arg, int line)
{
	int result;

	if (access(new_dir, F_OK) == 0)
	{
		custom_setenv(&env_list, "OLDPWD", cur_dir);
		free(cur_dir);
		chdir(new_dir);
		cur_dir = getcwd(NULL, 0);
		custom_setenv(&env_list, "PWD", cur_dir);
		free(cur_dir);
		result = EXIT_SUCCESS;
	}
	else
	{
		handle_cd_error(arg, line, env_list);
		free(cur_dir);
		result = STDERR_FILENO;
	}

	return (result);
}

/**
 * get_directory - change working directory
 * @cmd: user's typed in command
 * @env_list: enviromental linked list to retrieve paths
 *
 * Return: 0 if success 2 if failed
 */
char *get_directory(char **cmd, list_t *env_list)
{
	char *dir = NULL;

	if (cmd[1][0] == '~')
	{
		dir = fetch_env_v("HOME", env_list);
		dir = _strcat(dir, cmd[1]);
	}
	else if (cmd[1][0] == '-')
	{
		if (cmd[1][1] == '\0')
			dir = fetch_env_v("OLDPWD", env_list);
	}
	else
	{
		if (cmd[1][0] != '/')
		{
			dir = getcwd(dir, 0);
			dir = _strcat(dir, "/");
			dir = _strcat(dir, cmd[1]);
		}
		else
			dir = _strdup(cmd[1]);
	}

	return (dir);
}

/**
 * exec_cd - change working directory
 * @cmd: user's typed in command
 * @env_list: enviromental linked list to retrieve paths
 * @n: nth user command, to be used at error message
 *
 * Return: 0 if success 2 if failed
 */
int exec_cd(char **cmd, list_t *env_list, int n)
{
	char *cur_dir = NULL, *dir = NULL;
	int exit_stat = 0;

	cur_dir = getcwd(cur_dir, 0);
	if (cmd[1] != NULL)
	{
		dir = get_directory(cmd, env_list);
		exit_stat = change_dir(env_list, cur_dir, dir, cmd[1], n);
		free(dir);
	}
	else
		change_to_home_directory(env_list, cur_dir);
	free_pointer(cmd);
	return (exit_stat);
}

/**
 * get_user_line - Function for getting user line
 * Stores user line information in malloc and returns it
 * @line_ptr: Pointer to string to retrieve
 *
 * Return: number of characters read
 */
size_t get_user_line(char **line_ptr)
{
	ssize_t read_bytes;
	size_t total_bytes = 0;
	int end_of_line = 0, buffer_index;
	char buffer[1024];

	for (; end_of_line == 0 &&
				 (read_bytes = read(STDIN_FILENO, buffer, 1023));)
	{
		if (read_bytes == -1)
			return (-1);

		buffer[read_bytes] = '\0';

		for (buffer_index = 0; buffer[buffer_index] != '\0'; buffer_index++)
		{
			if (buffer[buffer_index] == '\n')
			{
				end_of_line = 1;
			}
		}

		if (total_bytes == 0)
		{
			read_bytes++;
			*line_ptr = malloc(read_bytes);
			*line_ptr = strcpy(*line_ptr, buffer);
			total_bytes = read_bytes;
		}
		else
		{
			total_bytes += read_bytes;
			*line_ptr = strcat(*line_ptr, buffer);
		}
	}

	return (total_bytes);
}

/**
 * mem_alloc - reallocate memory dynamically
 * @ptr: pointer to the memory dynamically allocated
 * @o_size: old size of the previously allocated
 * @n_size: new size of the reallocate memory
 *
 * Return: pointer to reallocated memory
 */

void *mem_alloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *local_ptr;
	unsigned int i = 0;

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (n_size == o_size)
		return (ptr);

	if (ptr == NULL)
	{
		local_ptr = malloc(n_size);
		if (local_ptr == NULL)
			return (NULL);
		else
			return (local_ptr);
	}

	local_ptr = malloc(n_size);
	if (local_ptr == NULL)
		return (NULL);

	while (i < o_size && i < n_size)
	{
		*((char *)local_ptr + i) = *((char *)ptr + i);
		i++;
	}

	free(ptr);
	return (local_ptr);
}

