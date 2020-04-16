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
	stva var[] = {{NULL, NULL, av, NULL, NULL, 0, 1}};
	size_t size = 0;
	ssize_t character;
	pid_t pid;
	char *line = NULL;
	struct stat st;
	/* write prompt only if it's from standard input */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "2$ ", 2);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{
		if (line[0] == '\n' || (line[0] == ' ' && line[1] != ' ') || line[0] == '\t')
			write(STDOUT_FILENO, "4$ ", 3), var->wcount++;
		else if (line[0] == '.' && line[1] == ' ')
			write(STDOUT_FILENO, "4$ ", 3), var->wcount++;
		else if (_strcmp(line, "exit\n") != 0)
		{
			if (var->wcount == 1)
				free(line);
			else
				free(line), free(var->pathtok), free(var->path);
			exit(EXIT_SUCCESS); }
		else
		{
			tokensfun(var, line), pid = fork();
			if (pid == -1)
				{	perror("Error:");
					exit(EXIT_FAILURE); }
			if (pid == 0)
			{
				execute(var);
				if (var->concat == NULL)
				{ free(var->tok), free(var->pathtok), free(var->path);
					break; }
				if (var->concat != NULL && stat(var->concat, &st) != -1)
					execve(var->concat, var->tok, environ);
			}
			else
				var->wcount++, wait(&pid);
			write(STDOUT_FILENO, "3$ ", 2), free_st(var);
		}
	}
	return (free(line), EXIT_SUCCESS);
}

/**
 * free_st - function that free the tokens of path
 * @var: global structure
 * Return: none
 */

void free_st(stva *var)
{
	free(var->tok);
	free(var->pathtok);
	free(var->path);
}

/**
 * execute - functions that execute final commands
 * @var: global structure
 * Return: none
 */
void execute(stva *var)
{
	_getenv(var, "PATH");
	_path(var);
	concatenate(var);
}
