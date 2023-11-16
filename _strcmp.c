#include "shell.h"

/**
 * __strcmp - Compares two strings
 * @str_len1: String to be compared
 * @str_len2: String to be compared
 * Return: 0 if are the same, > 0 if str1 is greater, < 0 if str2 is greater
 */
int __strcmp(char *str_len1, char *str_len2)
{
	int k;

	for (k = 0; str_len1[k] != '\0'; k++)
		;
	for (k = 0; str_len2[k] != '\0'; k++)
	{
		if (str_len1[k] != str_len2[k])
		{
			return (str_len1[k] - str_len2[k]);
		}
	}
	return (0);
}
