#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


void prompt(char **av, char **env);
void execute_command(char *command, char **env);
int __strcmp(char *str_len1, char *str_len2);
char *__strdup(char *str);
int __strlen(const char *str_len);
int __putchar(char c);
int print_str(char *str);



#endif
