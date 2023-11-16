#include "shell.h"
/**
 * builtin_exit - exit the shell
 * Return: void
 */
void builtin_exit(void)
{
	print_str("Exiting shell_________>\n");
	exit(0);
}
