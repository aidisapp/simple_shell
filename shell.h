#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <wait.h>
#include <dirent.h>
#include <signal.h>

extern char **environ;

/**
 * struct list - environmental variables linked list struct
 * @v: holds environmental variable string
 * @next_node: pointer to the next_node node head
 */
typedef struct list
{
	char *v;
	struct list *next_node;

} list_t;

int custom_print(char *str);
void print_string(char *str, int len);
int display_prompt(char **env);
int process_cmd(char *cmd, list_t *env, int cmd_line_num);
int execute_cmd(char **token, list_t *env, int cmd_line_num);
void handle_ctrl_c(int c);
void handle_ctrl_d(int arg, char *cmd, list_t *env);
int handle_builtin(char **token, list_t *env, int num, char **command);
void *mem_alloc(void *ptr, unsigned int o_size, unsigned int n_size);
size_t get_user_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *trim_space(char *str);
char *trim_space_alt(char *str);
char **custom_strtok(char *str, char *delm);
char **cont_delim(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int exec_cd(char **cmd, list_t *env_list, int n);
void pipe_commands(list_t *env);
char *match_path(char *str, list_t *env);
int exit_program(char **args, list_t *env_vars, int cmd_num, char **cmd);
int string_to_int(char *str);
int custom_exec(char **user_cmd, list_t *env_vars, int cmd_num);
void free_pointer(char **str);
void free_list(list_t *list);
int custom_env(char **cmd, list_t *env_list);
char *fetch_env_v(char *str, list_t *env);
list_t *linked_list(char **env_list);
list_t *add_list_end(list_t **head, char *str);
size_t print_linked_list(list_t *h);
int delete_list_idx(list_t **head, int index);
int unset_env(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int custom_setenv(list_t **env_list, char *var_name, char *path);
list_t *get_node(list_t *head, int index);
void change_to_home_directory(list_t *env, char *current);
int change_dir(list_t *env_list, char *cur_dir, char *new_dir,
char *arg, int line);
char *get_directory(char **cmd, list_t *env_list);
int find_env_list(list_t *env, char *str);
char *get_shell_name(list_t *env);
void err_not_found(char *str, int cmd_n, list_t *env);
void handle_cd_error(char *dir, int cmd_count, list_t *env);
void handle_exit_num(char *str, int c_n, list_t *env);
char *int_to_string(int num);

#endif

