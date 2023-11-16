#include "shell.h"

/**
 * __putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int __putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - writes the string char to stdout
 * @str: The str to print
 *
 * Return: count if it is succssful.
 */
int print_str(char *str)
{
	int i = 0, count = 0;

	while (str[i])
		count += __putchar(str[i++]);
	return (count);
}

