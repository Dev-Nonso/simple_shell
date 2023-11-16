#include "shell.h"
/**
 * get_path - Get the full path of a command.
 * @command: The command to be executed.
 * Return: The full path of the command or NULL if not found.
 */
char *get_path(char *command)
{
	char *path = getenv("PATH"), *path_copy = NULL;
	char command_path[1024], *dir;

	if (path == NULL)
	{
		print_str("PATH environment variable is not set.\n");
		return (NULL);
	}
	path_copy = __strdup(path);
	if (path_copy == NULL)
	{
		print_str("Failed to allocate memory for path copy.\n");
		return (NULL);
	}
	if (command == NULL || *command == '\0')
	{
		print_str("Command name is empty or NULL.\n");
		free(path_copy);
		return (NULL);
	}
	if (*command == '/')
		return (__strdup(command));
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		__strcpy(command_path, dir);
		if (command_path[__strlen(command_path) - 1] != '/')
			__strcat(command_path, "/");
		__strcat(command_path, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (__strdup(command_path));
		}
		dir = strtok(NULL, ":");
		printf("wonderful");
	}
	free(path_copy);
	return (NULL);
}
