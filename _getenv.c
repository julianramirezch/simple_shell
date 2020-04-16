#include "shell.h"

/**
 * _getenv - function that gets
 * the environment variable PATH
 * @word: variable PATH to search
 * Return: the found path.
 */

char *_getenv(char *word)
{
	/*extern char **environ;*/
	char *copy;
	unsigned int i = 0, j = 0, k = 0;
	//char *dup_environ;

	for (k = 0; word[k]; k++)
	{}
	while (environ[i])
	{
		copy = _strdup(environ[i]);
		while (word[j] == copy[j])
			j++;
		if (j == k)
		{
			printf(YELLOW"getenv[%i] es %s\n"RESET,i,copy);
			return (copy);
		}
		else
			i++, j = 0;
	}
	return ("retorna mierda");
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
	for (cont2 = 0 ; cont2 < cont ; cont2++)
		str2[cont2] = str[cont2];

	return (str2);
}