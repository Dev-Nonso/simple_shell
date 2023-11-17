#include "shell.h"

/**
 * __strlen - Sizes the length of a string
 * @str_len: String to be sized
 * Return: The length ot the string
 */

int __strlen(const char *str_len)
{
	int len_th = 0;

	if (str_len == NULL)
		return (0);

	while (str_len[len_th] != '\0')
		len_th++;
	return (len_th);
}
