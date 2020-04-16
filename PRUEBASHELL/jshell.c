#include "shell.h"

/**
 * sig_handler - signal handler for ctrl + c
 * @signum: signalnumber
 * Return: none.
 */
void sig_handler(int signum)
{
	if (signum == 2)
		write(STDOUT_FILENO, "\n1$ ", 3);
}

/**
 * main - Prompt
 * @argc: argument counter, unused argument
 * @av: argument value
 * Return: 1 on succes
 */
int main(__attribute__((unused))int argc, char **av)
{
	stva var[] = {{NULL, NULL, NULL, NULL, NULL, 0, 1}};
	size_t size = 0; // i = 0; //phcount = 0;
	ssize_t character;
	pid_t pid;
	struct stat st;
	char *line = NULL;
	/* write prompt only if it's from standard input */
	var->argv = av;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "2$ ", 2);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{
		if (_strcmp(line, "exit\n") == 1)
		{	
			free(line);
			free(var->concat);
			exit(EXIT_SUCCESS);
		}

		tokensfun(var,line);// tokens el line
		_getenv(var, "PATH"); // solo llamamos la funcion;
		_path(var);
		concatenate(var);
		
//		phcount = count_direc(var->pathtok);
		 // var->tok es tokens de la estructura
		pid = fork();

		if (pid == -1)
			{	perror("Error:");
				exit(EXIT_FAILURE); }
		if (pid == 0)
		{
//			while (var->pathtok[i])
//			{
				//printf("llega antes de la concat\n");
//				if (i == (phcount - 1))
//					commmand_not(var->tok[0], arg, wcount, "not found\n");
				if (var->concat != NULL && stat(var->concat, &st) != -1)					
					{
						printf(YELLOW"var->concat es %s\n"RESET, var->concat);
						execve(var->concat, var->tok, environ);
					}
//				i++;
//			}
		}
		else
			var->wcount++, wait(&pid);
		write(STDOUT_FILENO, "3$ ", 2);
		free_st(var);
	}
	//free(var->concat);
	free(line);
	return (EXIT_SUCCESS);
}
