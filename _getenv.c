#include "shell.h"

/**
 * _getenv - function that gets
 * the environment variable PATH
 * @word: variable PATH to search
 * Return: the found path.
 */

char *_getenv(char *word)
{
	/*extern char **environ;*/
	char *copy;
	unsigned int i = 0, j = 0, k = 0;

	for (k = 0; word[k]; k++)
	{}
	while (environ[i])
	{
		copy = environ[i];
		while (word[j] == copy[j])
			j++;
		if (j == k)
		{
			return (copy);
		}
		else
			i++, j = 0;
	}
	return (NULL);
}
