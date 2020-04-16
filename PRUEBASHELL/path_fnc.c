#include "shell.h"

/**
 * _path - function that create an array of paths.
 * @glres: getline result
 * @delim: delimiter for separate
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
//	int x = 0;
//		while (var->pathtok[x])
//		{
//			printf(GREEN"desde _path var->pathtok es %s\n"RESET, var->pathtok[x]);
//			x++;
//		}
}
