#include "shell.h"

/**
 * _getenv - function that gets
 * the environment variable PATH
 * @word: variable PATH to search
 * Return: the found path.
 */

void _getenv(stva *var,char *word)
{
	char *copy;
	char *path_o;
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
			path_o = _strdup(copy); //duplicado del path;
			var->path = path_o;
			break;
		}
		else
			i++, j = 0;
	}
}
