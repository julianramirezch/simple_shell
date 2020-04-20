#include "shell.h"

/**
 * concatenate - concatenates two strings
 * @var: global structure
 * Return: the new string concatenate or string2 if
 * can't be concatenated
 */

void concatenate(stva *var)
{

	int  len1;
	struct stat st;
	DIR *dir = NULL;

	dir = opendir(var->tok[0]);
	len1 = _strlen(var->tok[0]);

	if (dir)
	{ closedir(dir);
		commmand_not(var, "Permission denied\n");
		var->status = 126, var->concat = NULL;
		return; }
	if (var->tok[0][0] == '.' || var->tok[0][0] == '/') /* ./ls o /ls /bin/ls */
	{
		if (stat(var->tok[0], &st) == 0)
		{
			if (access(var->tok[0], X_OK) == 0)
			{
				var->slash = var->tok[0];
				var->concat = NULL, var->status = 0;
				return;
			}
			else
			{ commmand_not(var, "not found\n");
				var->status = 126;
				return; }
		}
		else
		{ var->concat = NULL, var->status = 127;
			commmand_not(var, "not found\n");
			return; }
	}
	else
		loop_concatenate(var, len1);
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
 * Return: 0 if success
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (-1);
	return (0);
}

/**
 * _strdup- returns a pointer to a newly allocated space in memory.
 * @str: Character.
 * Return: str
 */

char *_strdup(char *str)
{
	int cont = 0, cont2 = 0, cont3 = 0;
	char *str2;

	if (str == NULL)
		return (NULL);
	if (_strcmp(str, "") == 0)
		return (NULL);
	for (cont = 0; str[cont]; cont++)
	{}
	cont++;
	str2 = malloc(sizeof(char) * (cont - 4));
	if (str2 == NULL)
		return (NULL);
	for (cont2 = 5; cont2 < cont; cont2++, cont3++)
	{
		str2[cont3] = str[cont2];
	}

	return (str2);
}
