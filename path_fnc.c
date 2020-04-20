#include "shell.h"

/**
 * _path - function that create an array of paths.
 * @var: global structure
 * Return: array of paths.
 */

void _path(stva *var)
{
	char *string, *token = NULL;
	char **finalargs = NULL;
	int bfc = 0, i = 0, j = 0;

	if (var->path) /*if path exists*/
	{
		for (j = 0; var->path[j]; j++)
		{}
		string = malloc(sizeof(char) * (j + 1));
		/*make a copy of the entry string*/
		j = 0;
		while (var->path[j])
			string[i] = var->path[j], i++, j++;
		string[i] = '\0';
		/*made the tokens to know how many words are*/
		token = strtok(string, ":");
		while (token != NULL)
			token = strtok(NULL, ":"), bfc++;
		/*malloc size / set variables to 0*/
		finalargs = malloc(sizeof(char *) * (bfc + 1));
		i = 0, bfc = 0;
		/*set string again to original*/
		j = 0;
		while (var->path[j])
			string[i] = var->path[j], i++, j++;
		string[i] = '\0';
		/*point to each word in each tokens*/
		token = strtok(var->path, ":");
		while (token != NULL)
		{ finalargs[bfc] = token;
			token = strtok(NULL, ":");
			bfc++; }
		/*returns pointer to works list*/
		finalargs[bfc] = NULL;
		var->pathtok = finalargs;
		free(string);
	}
	else
		return;
}

/**
 * env_print - Print env
 * @var: Structure
 */
void env_print(stva *var)
{

	int i = 0;
	int length = 0;

	if (!environ)
	{
		var->path = NULL;
		var->slash = NULL;/* /bin/gcls */
		var->status = -1;
		return;
	}
	while (environ[i])
	{
		var->concat = NULL;
		var->slash = NULL;
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
