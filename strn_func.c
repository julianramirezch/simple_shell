#include "shell.h"

/**
 * concatenate - concatenates two strings
 * @string1: is the path to concatenate
 * @string2: is the command or arg[0] from main
 * Return: the new string concatenate or string2 if
 * can't be concatenated
 */

char *concatenate(char *string1, char *string2)
{
	char *buffer;
	int i, len2;

	i = _strlen(string1);
	len2 = _strlen(string2);

	buffer = malloc(sizeof(char) * i + len2 + 2);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (string1[i])
		buffer[i] = string1[i], i++;

	if (string2[0] != '/')
	{
		len2 = 0;
		buffer[i] = '/';
		i++;
		while (string2[len2])
			buffer[i] = string2[len2], i++, len2++;
		buffer[i] = '\0';
		return (buffer);
	}
	free(buffer);
	return (string2);
}

/**
 * _strlen - calculates size of string
 * @s: string
 * Return: integer
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *(s + len) != '\0'; len++)
	{};
	return (len);
}

/**
 * _strcmp - compare two strings
 * @s1: string1
 * @s2: string2
 * Return: 1 if success
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0 ; s2[j] != '\0' ; j++)
	{
		if (s1[j] != s2[j])
			return (0);
	}
	return (1);
}
