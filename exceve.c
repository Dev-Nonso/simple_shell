#include "shell.h"
/**
 * execute_command - Execute a specified command.
 * @command: The command to be executed.
 * @env: The array of environment variables.
 * Return: No return value.
 */
void execute_command(char *command, char **env)
{
	char *argv[11], *cmdpath;
	pid_t child_pid;
	int status, j;
	char *delim = " \n\t\r";

	j = 0;
	argv[0] = strtok(command, delim);
	while (argv[j] != NULL)
		argv[++j] = strtok(NULL, delim);
	argv[j] = NULL;
	if (__strcmp(argv[0], "cd") == 0)
	{
		builtin_cd(argv[0]);
	}
	else if (__strcmp(argv[0], "env") == 0)
	{
		for (; *env; env++)
		{
			env_var();
			continue;
		}
	}
	if (__strcmp(argv[0], "exit") == 0)
	{
		free(command);
		exit(0);
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			free(command);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			printf("work work work");
			cmdpath = get_path(argv[0]);
			if (cmdpath != NULL)
			{
				if (execve(cmdpath, argv, env) == -1)
					print_str("/hsh: No such file or directory exist\n");
			}
		}
		else
			wait(&status);
	}
}
