#include "shell.h"

/**
 * env_var - Get the environment variables
 *
 * Return: A pointer to the environment variables.
 */

char **env_var()
{
	int k;
	/*char **env = environ;*/
	char line = '\n';

	for (k = 0; environ[k] != NULL; k++)
		write(1, environ[k], _strlen(environ[k]));
	write(1, &line, 1);

	return (environ);
}
