#include "shell.h"

/**
 * commmand_not - print the error message when
 * command can't be found
 * @com: command recived.
 * @arg: arrguments recived.
 * @cont: count the iterations in the main function
 * @msg: message to be printed
 * Return: integer.
 */
int commmand_not(char *com, char *arg, int cont, char *msg)
{
	int len_com = 0, len_arg = 0, wcn = 0, many = 0, cont2 = cont;
	char *number;

	len_com = _strlen(com);
	len_arg = _strlen(arg);
	write(STDERR_FILENO, arg, len_arg);
	write(STDERR_FILENO, ": ", 2);

	if (cont < 10)
	{
		number = malloc(sizeof(char) * 2);
		number[wcn] = cont + 48;
		number[wcn + 1] = '\0';
		write(STDERR_FILENO, number, _strlen(number));
		free(number);
	}
	else
	{
		while (cont2 != 0)
			cont2 /= 10, many++;
		number = malloc(sizeof(char) * (many + 1));
		number[many] = '\0';
		while (cont != 0)
		{
			many--;
			number[many] = cont % 10 + 48;
			cont /= 10;
		}
		write(STDERR_FILENO, number, _strlen(number));
		free(number);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, len_com);
	write(STDERR_FILENO, ": ", 2);
	if (access(com, X_OK) == 0)
		return (write(STDERR_FILENO, "Permission denied\n", 18)); /*mensaje denied*/
	if (access(com, X_OK) == -1)
		return (write(STDERR_FILENO, msg, _strlen(msg))); /*mensaje nor found*/
	return (0);
}

/**
 * count_direc - count the directorys inside PATH
 * @direct: folder to count
 * Return: cant of folders found.
 */

size_t count_direc(char **direct)
{
	size_t i = 0;

	while (direct[i])
		i++;
	i--;
	return (i);
}


/**
 * freepathtokens - function that free the tokens of path
 * @pathtokens: tokens to be free
 * Return: none
 */

void freepathtokens(char **pathtokens)
{
	int loop = 0;

	while (pathtokens[loop])
		free(pathtokens[loop]), loop++;
}
