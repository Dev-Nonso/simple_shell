#include "shell.h"

/**
 * __strdup - Duplicates a string
 * @str: String to be duplicated
 * Return: Pointer to the duplicated string
 */
char *__strdup(char *str)
{
	unsigned int i, length;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;
	dup = (char *) malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}
