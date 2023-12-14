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
 * @next_node: points to next_node node
 */
typedef struct list
{
	char *v;
	struct list *next_node;

} list_t;

int display_prompt(char **env);
int process_cmd(char *cmd, list_t *env, int cmd_line_num);
int execute_cmd(char **token, list_t *env, int cmd_line_num);
void ctrl_c(int n);
void ctrl_D(int i, char *command, list_t *env);
int handle_builtin(char **token, list_t *env, int num, char **command);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *trim_space(char *str);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
void non_interactive(list_t *env);
char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void free_double_ptr(char **str);
void free_linked_list(list_t *list);
int _env(char **str, list_t *env);
char *get_env(char *str, list_t *env);
list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t print_list(list_t *h);
int delete_nodeint_at_index(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int find_env(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);
char *int_to_string(int num);

#endif

