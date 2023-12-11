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


int custom_print(char *str);
void custom_error(char *args);
void read_input_cmd(char *command, size_t size);
void exec_cmd(const char *command);

#endif

