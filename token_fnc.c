#include "shell.h"

/**
 * tokensfun - separate tokens by " ".
 * @var: Structure
 * @line: line write in command line.
 * Return: 0 is succes.
 */

void tokensfun(stva *var, char *line)
{
	char *string, *token = NULL, **tokens = NULL;
	int index = 0, copy = 0, len = 0;

	/*conoce tamaño y asigna nueva mem*/
	for (len = 0; line[len]; len++);
	string = malloc(sizeof(char) * (len));
	/*hace una copia del string de entrada*/
	while (line[copy] != '\n')
		string[copy] = line[copy], copy++;
	string[copy] = '\0';
	/*crea el token para saber cuantas palabras son*/
	token = strtok(string, " \n");
	while (token != NULL)
		token = strtok(NULL, "  \n"), index++;
	/*asigna tamaño a array de palabras / setea variables a 0*/
	tokens = malloc(sizeof(char *) * (index + 1)); /* copy = 0; */
	index = 0;
	/*reasigna los espacios al string de copia*/
	/*apunta cada palabra a cada posicion del array de palabras*/
	token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, " \n\t"), index++;
	}
	free(string);
	tokens[index] = NULL;
	var->tok = tokens;
}

/**
 * free_exit - functions that free in exit commands
 * @var: global structure
 * @line: Pointer to line
 * Return: none
 */
void free_exit(stva *var, char *line)
{
	if (var->wcount == 1)
		free(line);
	else
	{
		free(line);
		//free(var->pathtok);
		//free(var->path);
	}
	exit(var->status);
}
