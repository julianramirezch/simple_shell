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
	for (len = 0; line[len]; len++)
	{}
	string = malloc(sizeof(char) * (len));
	/*hace una copia del string de entrada*/
	while (line[copy] != '\n')
		string[copy] = line[copy], copy++;
	string[copy] = '\0';
	/*crea el token para saber cuantas palabras son*/
	token = strtok(string, " \n\t");
	while (token != NULL)
		token = strtok(NULL, "  \n\t"), index++;
	/*asigna tamaño a array de palabras / setea variables a 0*/
	tokens = malloc(sizeof(char *) * (index + 1)); /* copy = 0; */
	index = 0;
	/*reasigna los espacios al string de copia*/
	/*apunta cada palabra a cada posicion del array de palabras*/
	token = strtok(line, " \n\t");
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
int free_exit(stva *var, char *line)
{
	if (var->wcount == 1)
		free(line);
	else
	{
		free(line);
	}

	exit(0);
	return (0);
}

/**
 * loop_concatenate - Loop concatenate
 * @var: Structure.
 * @len1: len string
 */
void loop_concatenate(stva *var, int len1)
{
	int x = 0, y = 0, len2;
	struct stat st;

	while (var->pathtok[x]) /* la ruta */
	{
		len2 = _strlen(var->pathtok[x]); /* len de la ruta */
		var->concat = malloc(sizeof(char) * (len1 + len2 + 2));
		while (var->pathtok[x][y])
			var->concat[y] = var->pathtok[x][y], y++; /*pon0e la ruta */
		var->concat[y] = '/';
		y++;
		len1 = 0;
		while (var->tok[0][len1])
			var->concat[y] = var->tok[0][len1], y++, len1++; /* cpone comando */
		var->concat[y] = '\0';
		if (stat(var->concat, &st) == 0) /* concatenate*/
		{
			if (access(var->concat, X_OK) == 0)
			{
				var->status = 0;
				return;
			}
			else
			{ commmand_not(var, "not found\n");
				var->status = 126;
				return; }
		}

		if (var->pathtok[x + 1] == NULL)
		{
			commmand_not(var, "not found\n");
			var->status = 127;
		}
		free(var->concat);
		var->concat = NULL;
		y = 0;
		x++;
	}
}
