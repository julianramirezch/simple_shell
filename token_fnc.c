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

	/*meet the length of the string*/
	for (len = 0; line[len]; len++)
	{}
	line[len - 1] = '\0';
	string = malloc(sizeof(char) * (len));
	/*make a copy of the entry string*/
	while (line[copy] != '\0')
		string[copy] = line[copy], copy++;
	string[copy] = '\0';
	/*made the tokens to know how many words are*/
	token = strtok(string, " \t");
	while (token != NULL)
		token = strtok(NULL, "  \t"), index++;
	/*malloc size / set variables to 0*/
	tokens = malloc(sizeof(char *) * (index + 1)); /* copy = 0; */
	index = 0;
	/*point to each word in each tokens*/
	token = strtok(line, " \t");
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, " \t"), index++;
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

	exit(var->status);
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

	if (var->pathtok)
	{
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
				{ var->status = 0;
					return;
				}
				else
				{ commmand_not(var, "not found\n");
					var->status = 126;
					return; }
			}
			if (var->pathtok[x + 1] == NULL)
			{ commmand_not(var, "not found\n");
				var->status = 127; }
			free(var->concat);
			var->concat = NULL;
			y = 0, x++;
		}
	}
	else
	{ commmand_not(var, "not found\n");
		var->status = 127;
		return; }
}
