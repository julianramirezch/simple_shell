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
void commmand_not(stva *var, char *msg)
{
	int len_com = 0, len_arg = 0, wcn = 0, many = 0, cont2 = var->wcount;
	char *number;

	len_com = _strlen(var->tok[0]);
	len_arg = _strlen(var->argv[0]);
	write(STDERR_FILENO, var->argv[0], len_arg);
	write(STDERR_FILENO, ": ", 2);

	if (var->wcount < 10)
	{
		number = malloc(sizeof(char) * 2);
		number[wcn] = var->wcount + 48;
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
		while (var->wcount != 0)
		{
			many--;
			number[many] = var->wcount % 10 + 48;
			var->wcount /= 10;
		}
		write(STDERR_FILENO, number, _strlen(number));
		free(number);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, var->tok[0], len_com);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));

//	free(var->concat);
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
 * free_st - function that free the tokens of path
 * @pathtokens: tokens to be free
 * Return: none
 */

void free_st (stva *var)
{
	free(var->tok);
	free(var->pathtok);
//	free(var->argv);
	free(var->path);
//	free(var->concat);
	//free(var->status);
	//free(var->wcount);
	//free(var->concat);
}

