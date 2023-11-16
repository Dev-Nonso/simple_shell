#include "shell.h"

/**
 * execute_command - Execute a specified command.
 * @command: The command to be executed.
 * @env: The array of environment variables.
 *
 * Return: No return value.
 */
void execute_command(char *command, char **env)
{
	char *argv[] = {NULL, NULL};
	pid_t child_pid;
	int status;

	argv[0] = command;
	child_pid = fork();

	if (child_pid == -1)
	{
		free(command);
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			print_str("/hsh: No such file or directory exists\n");
	}
	else
		wait(&status);
}
