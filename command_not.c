#include "shell.h"

/**
 * commmand_not - print the error message when
 * command can't be found
 * @var: global structure.
 * @msg: message to be printed
 * Return: integer.
 */
void commmand_not(stva *var, char *msg)
{
	int len_com = 0, len_arg = 0, wcn = 0, many = 0;
	int counter = var->wcount, cont2 = counter;
	char *number;

	len_com = _strlen(var->tok[0]);
	len_arg = _strlen(var->argv[0]);
	write(STDERR_FILENO, var->argv[0], len_arg);
	write(STDERR_FILENO, ": ", 2);

	if (counter < 10)
	{
		number = malloc(sizeof(char) * 2);
		number[wcn] = counter + 48;
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
		while (counter != 0)
		{
			many--;
			number[many] = counter % 10 + 48;
			counter /= 10;
		}
		write(STDERR_FILENO, number, _strlen(number));
		free(number);
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, var->tok[0], len_com);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));
}
