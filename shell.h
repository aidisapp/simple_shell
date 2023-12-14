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

#define MAX_INPUT_SIZE 1024

extern char **environ;

int custom_print(char *str);
void custom_error(char *args);
void prompt(void);
void handle_command(char *input);

#endif

