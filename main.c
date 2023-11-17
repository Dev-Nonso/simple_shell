#include "shell.h"
/**
 * main - Entry point for the shell program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Return: Always returns 0.
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av, env);
		/*exemm(av, env);*/
	}

	return (0);
}
