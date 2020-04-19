#include "shell.h"

/**
 * _getenv - function that gets
 * the environment variable PATH
 * @var: global structure
 * @word: variable PATH to search
 * Return: the found path.
 */

void _getenv(stva *var, char *word)
{
	char *path_o;
	unsigned int i = 0, j = 0, k = 0;

	for (k = 0; word[k]; k++)
	{}
	if (!environ)
	{
		var->path = NULL;
		return;
	}
	while (environ[i])
	{
		while (word[j] == environ[i][j])
			j++;
		if (j == k)
		{
			path_o = _strdup(environ[i]);
			var->path = path_o;
			break;
		}
		else
			i++, j = 0;
	}
}
