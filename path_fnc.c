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
	{
		finalargs[bfc] = token;
		token = strtok(NULL, ":");
		bfc++;
	}
	/*retorna el puntero a la lista de palabras*/

	finalargs[bfc] = NULL;
	var->pathtok = finalargs;
	free(string);
}

/**
 * _env - prints the enviroment variable
 * @var: global structure
 * Return: none
 */
void _env(char *line)
{
	int env = 0;

	if (_strcmp(line, "env\n") == 0)
	{
		while (environ[env])
		{
			write(STDOUT_FILENO, environ[env], _strlen(environ[env])),
			env++;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
}
