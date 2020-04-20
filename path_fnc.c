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
	/*conoce tamaño y asigna nueva mem*/
	if (var->path) /*if path exists*/
	{
		for (j = 0; var->path[j]; j++)
		{}
		string = malloc(sizeof(char) * (j + 1));
		/*hace una copia del string de entrada*/
		j = 0;
		while (var->path[j])
			string[i] = var->path[j], i++, j++;
		string[i] = '\0';
		/*crea el token para saber cuantas palabras son*/
		token = strtok(string, ":");
		while (token != NULL)
			token = strtok(NULL, ":"), bfc++;
		/*asigna tamaño a array de palabras / setea variables a 0*/
		finalargs = malloc(sizeof(char *) * (bfc + 1));
		i = 0, bfc = 0;
		/*reasigna los espacios al string de copia*/
		j = 0;
		while (var->path[j])
			string[i] = var->path[j], i++, j++;
		string[i] = '\0';
		/*apunta cada palabra a cada posicion del array de palabras*/
		token = strtok(var->path, ":");
		while (token != NULL)
		{ finalargs[bfc] = token;
			token = strtok(NULL, ":");
			bfc++;
		}
		/*retorna el puntero a la lista de palabras*/
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
void env_print(__attribute__((unused))stva *var)
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
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
