#include "shell.h"

/**
 * prompt - Display a prompt and read user input.
 * @av: An array of strings containing program arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Return: No return value.
 */
void prompt(char **av, char **env)
{
	char *string = NULL;
	int i;
	size_t n = 0;
	ssize_t num_char;

	(void)av;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_str("($) ");
			fflush(stdout);
		}

		num_char = getline(&string, &n, stdin);

		if (num_char == -1)
		{
			free(string);
			break;
		}
		if (num_char == 1 && string[0] == '\0')
			continue;

		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}

		execute_command(string, env);

		free(string);
		string = NULL;
	}
}
