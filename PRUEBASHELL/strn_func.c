#include "shell.h"

/**
 * concatenate - concatenates two strings
 * @string1: is the path to concatenate
 * @string2: is the command or arg[0] from main
 * Return: the new string concatenate or string2 if
 * can't be concatenated
 */
//concatenate(var->pathtok[i], var->tok[0]);
void concatenate(stva *var)
{
	int x = 0, y = 0, len1, len2;
	struct stat st;
	len1 = _strlen(var->tok[0]);
	printf("len1 es [%i]\n", len1);
	DIR *dir = NULL;

	dir = opendir(var->tok[0]);
	if (dir != NULL && access(var->tok[0], X_OK) == 0) /* /bin */
	{
		var->status = 126;
		printf("LLEGUE A LA VALIDACION*******1\n");
		closedir(dir);
		commmand_not(var, "Permission denied\n");
	}
	else if (dir == NULL && access(var->tok[0], X_OK) == 0) /* /bin/ls */
	{
		printf("LLEGUE A LA VALIDACION*******2\n");
		closedir(dir);
		var->concat = var->tok[0];
	}
	else if (var->tok[0][0] == '.' && var->tok[0][1] == '\0') /* . */
	{
		printf("LLEGUE A LA VALIDACION*******3\n");
		var->concat = var->tok[0];
	}
	else if (var->tok[0][0] == '.' || var->tok[0][0] == '/') /* ./ls o /ls */
	{
		printf("LLEGUE A LA VALIDACION*******4\n");
		var->status = 127;
		commmand_not(var, "not found\n");
	}
	else
	{
		printf("LLEGUE A LA VALIDACION*******5\n");
		while (var->pathtok[x]) /* la ruta */
		{
		//	printf(RED"var->pathtok[%i] es: %s\n"RESET,x, var->pathtok[x]);
			len2 = _strlen(var->pathtok[x]); /* len de la ruta */
			printf("LEN2 VALE: %i\n",len2);
			var->concat = malloc(sizeof(char) * (len1 + len2 + 2));
			while (var->pathtok[x][y])
				var->concat[y] = var->pathtok[x][y], y++; /*pon0e la ruta */
			var->concat[y] = '/';
		//	printf(RED"var->concat 1 es: %s\n"RESET,var->concat);
			y++;
			len1 = 0;
			while (var->tok[0][len1])
				var->concat[y] = var->tok[0][len1], y++, len1++; /* cpone comando */
			var->concat[y] = '\0';
		//	printf(RED"var->concat 2 es: %s\n"RESET,var->concat);
			if (stat(var->concat, &st) == -1) /* concatenada con comandos mierda */
			{
				//printf("LA CONCATENADA ES : [[%s]]\n", var->concat);
				free(var->concat);
				y = 0;
				x++;
			}
			else if (stat(var->concat, &st) == 0) /* concatenada con comandos chimbas */
			{
				break;
			}
		}
		if (var->pathtok[x] == NULL)
		{
			printf("LLEGUE A LA VALIDACION*******6\n");
			var->status = 127;
			var->concat = NULL;
			commmand_not(var, "not found\n");
		}
	}
}

/**
 * _strlen - calculates size of string
 * @s: string
 * Return: integer
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; *(s + len) != '\0'; len++)
	{};
	return (len);
}

/**
 * _strcmp - compare two strings
 * @s1: string1
 * @s2: string2
 * Return: 1 if success
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0 ; s2[j] != '\0' ; j++)
	{
		if (s1[j] != s2[j])
			return (0);
	}
	return (1);
}

/**
 * _strdup- returns a pointer to a newly allocated space in memory.
 * @str: Character.
 * Return: str
 */

char *_strdup(char *str)
{
	int cont;
	int cont2;
	char *str2;
	if (str == NULL)
		return (NULL);
	for (cont = 0; str[cont]; cont++)
	{}
	cont++;
	str2 = malloc(sizeof(char) * cont);
	if (str2 == NULL)
		return (NULL);
	for (cont2 = 0; cont2 < cont; cont2++)
	{
		str2[cont2] = str[cont2];
	}
	return (str2);
}
