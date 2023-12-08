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

int custom_print(char *str);
void prompt(void);
void read_input_cmd(char *command, size_t size);
void exec_cmd(const char *command);

#endif

