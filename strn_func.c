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

	if(dir)
	{
		closedir(dir);
		commmand_not(var, "Permission denied\n");
		var->status= 126;
		return;
	}

	if (var->tok[0][0] == '.' || var->tok[0][0] == '/') /* ./ls o /ls */
	{
		if (stat(var->tok[0], &st) == 0)
		{
			if (access(var->tok[0], X_OK) == 0)
			{
				var->concat = var->tok[0];
				var->status = 0;
				return;
			}
			else
			{
				printf("EROORORORO\n");/*SHOW ERROR MESSAGE*/
				var->status = 126;
				return;
			}
		}
		else
		{
			var->concat = NULL;
			commmand_not(var, "Not found\n");
			var->status = 127;
			return;
		}
	}
		 /* tiene que llegar al execve - doble validacion */
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
 * Return: 1 if success
 */
int _strcmp(char *s1, char *s2)
{
	int i, size1, size2;

	for (size1 = 0; *(s1 + size1) != '\0'; size1++)
	{}
	for (size2 = 0; *(s2 + size2) != '\0'; size2++)
	{}
	size1--;
	size2--;
	for (i = 0; *(s1 + i) != '\0' && *(s2 + i) != '\0'; i++)
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
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
	/* str2[cont2] = '\0'; */
	return (str2);
}

/**
 *_validation: First Validation
 * @var: Structure
 */
void _validation (stva *var)
{
	struct stat st;

	if (stat(var->tok[0], &st) == 0)
		{
			if (access(var->tok[0], X_OK) == 0)
			{
				var->concat = var->tok[0];
				var->status = 0;
				return;
			}
			else
			{
				printf("EROORORORO\n");/*SHOW ERROR MESSAGE*/
				var->status = 126;
				return;
			}
		}
		else
		{
			_notfound(var);
			return;
		}
}