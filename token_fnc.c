#include "shell.h"

/**
 * tokensfun - separate tokens by " ".
 * @var: Structure
 * @line: line write in command line.
 * Return: 0 is succes.
 */

int tokensfun(stva *var, char *line)
{
	char *string,  **tokens = NULL, *token = NULL;
	int index = 0, copy = 0, len = 0;

	/*conoce tamaño y asigna nueva mem*/
	for (len = 0; line[len]; len++)
	{}
	string = malloc(sizeof(char) * (len));
	/*hace una copia del string de entrada*/
	while (line[copy] != '\n')
		string[copy] = line[copy], copy++;
	string[copy] = '\0';
	/*asigna tamaño a array de palabras / setea var iables a 0*/
	tokens = malloc(2048); /* copy = 0; */
	index = 0;
	/*apunta cada palabra a cada posicion del array de palabras*/
	token = strtok(line, " \n");
	if (token)
	{
		while (token != NULL)
		{
			tokens[index] = token;
			token = strtok(NULL, " \n\t"), index++;
		}
	}
	else
	{
		free(string);
		free(tokens);
		return (0);
	}
	free(string);
	tokens[index] = NULL;
	var->tok = tokens;
	return (1);
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
		/* free(var->pathtok);*/
		/*free(var->path);*/
	}
	exit(var->status);
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
			{ commmand_not(var, "Not found\n");
				var->status = 126;
				return; }
		}

		if (var->pathtok[x + 1] == NULL)
		{
			commmand_not(var, "Not found\n");
			free(var->tok);
			var->status = 127;
		}
		free(var->concat);
		var->concat = NULL;
		y = 0;
		x++;
	}
}
