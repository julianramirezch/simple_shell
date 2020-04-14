#include "shell.h"

/**
 * _path - function that create an array of paths.
 * @glres: getline result
 * @delim: delimiter for separate
 * Return: array of paths.
 */

char **_path(char *glres, char *delim)
{
	char *string, *token = NULL;
	char **finalargs = NULL;
	int bfc = 0, i = 0, j = 0;
	/*conoce tamaño y asigna nueva mem*/
	for (j = 0; glres[j]; j++)
	{}
	string = malloc(sizeof(char) * j + 1);
	/*hace una copia del string de entrada*/
	while (glres[i])
		string[i] = glres[i], i++;
	string[i] = '\0';
	/*crea el token para saber cuantas palabras son*/
	token = strtok(string, delim);
	while (token != NULL)
		token = strtok(NULL, delim), bfc++;
	/*asigna tamaño a array de palabras / setea variables a 0*/
	finalargs = malloc(sizeof(char *) * (bfc));
	i = 0, bfc = 0;
	/*reasigna los espacios al string de copia*/
	while (glres[i])
		string[i] = glres[i], i++;
	string[i] = '\0';
	/*apunta cada palabra a cada posicion del array de palabras*/
	token = strtok(glres, delim);
	while (token != NULL)
	{
		finalargs[bfc] = token;
		token = strtok(NULL, delim);
		bfc++;
	}
	/*retorna el puntero a la lista de palabras*/
	free(string);
	return (finalargs);
}
