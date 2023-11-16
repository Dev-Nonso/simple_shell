#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>


extern char **environ;

void prompt(char **av, char **env);
void execute_command(char *command, char **env);
char *get_path(char *command);
void builtin_cd(char *args);

/* support fuctions like strcmp, strdup, strlen, strcpy and strcat*/
int __strcmp(char *str_len1, char *str_len2);
char *__strdup(char *str);
int __strlen(const char *str_len);
char *__strcpy(char *dest, char *src);
char *__strcat(char *dest, char *src);


/* function for print to the screen*/
int __putchar(char c);
int print_str(char *str);

#endif
