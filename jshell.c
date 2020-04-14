#include "shell.h"

/**
 * sig_handler - signal handler for ctrl + c
 * @signum: signalnumber
 * Return: none.
 */
void sig_handler(int signum)
{
	if (signum == 2)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Prompt
 * @argc: argument counter, unused argument
 * @av: argument value
 * Return: 1 on succes
 */
int main(__attribute__((unused))int argc, char **av)
{
	char *line = NULL, **ttk = NULL, *concat, *arg = av[0];
	char **pathtokens = _path(_getenv("PATH"), ":=");
	size_t size = 0, i = 0, phcount = count_direc(pathtokens), wcount = 1;
	ssize_t character;
	pid_t pid;
	struct stat st;
	/* write prompt only if it's from standard input */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{
		if (_strcmp(line, "exit\n") == 1)
		{	free(line);
			exit(EXIT_SUCCESS); }
		ttk = tokensfun(line);
		pid = fork();

		if (pid == -1)
			{	perror("Error:");
				exit(EXIT_FAILURE); }
		if (pid == 0)
		{
			while (pathtokens[i])
			{
				concat = concatenate(pathtokens[i], ttk[0]);
				if (i == (phcount - 1))
					commmand_not(ttk[0], arg, wcount, "not found\n");
				if (stat(concat, &st) == 0)
					execve(concat, ttk, environ);
				i++;
			}
		}
		else
			wcount++, wait(&pid);
		write(STDOUT_FILENO, "$ ", 2);
	}
	free(line), free(pathtokens), free(ttk);
	return (EXIT_SUCCESS);
}
