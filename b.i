#include "shell.h"
/**
 * builtin_cd - Change directory based on the provided arguments.
 * @args: An array of strings containing program arguments.
 *
 * Return: No return value.
 */
void builtin_cd(char *args)
{
	char cwd[1024];

	if (args == NULL)
	{
		/*If no argument is given, change to $HOME*/
		if (chdir(getenv("HOME")) != 0)
		{
			perror("chdir() failed");
		}
	}
	else if (strcmp(args, "-") == 0)
	{
		/*If the argument is "-", change to the previous directory*/
		if (chdir("..") != 0)
		{
			perror("chdir() failed");
		}
	}
	else
	{
		/*Change to the given directory*/
		if (chdir(args) != 0)
		{
			perror("chdir() failed");
		}
	}

	/*Update the PWD environment variable*/
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
	else
	{
		perror("getcwd() failed");
	}
}
