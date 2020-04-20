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
 * _fork - fork the process to work in child pid
 * @var: global structure
 * @line: buffer that contains the getline buff
 * @pid: is the pid proccess
 * Return: 0 succes
 */

int _fork(stva *var, char *line, pid_t pid)
{
	tokensfun(var, line);

	if (var->tok[0] == NULL || _strcmp(var->tok[0], ".") == 0)
	{
		free(var->tok);
		return (0);
	}

	execute(var);
	if (_strcmp("env", var->tok[0]) != 0)
		concatenate(var);
	if (var->status == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (var->concat != NULL) /* concatenate ok */
				execve(var->concat, var->tok, environ);
			if (var->slash != NULL) /* /bin/ls or ./ok */
				execve(var->slash, var->tok, environ);
		}
		else
		{
			wait(&pid);
			var->status = WEXITSTATUS(pid);
		}
	}
	free_st(var);
	if (!environ)
		var->status = 0;
	return (0);
}
/**
 * main - Prompt
 * @argc: argument counter, unused argument
 * @av: argument value
 * Return: 1 on succes
 */
int main(__attribute__((unused))int argc, char **av)
{
	size_t size = 0;
	ssize_t character;
	pid_t pid = 0;
	char *line = NULL;
	stva var;

	var.tok = NULL, var.pathtok = NULL, var.argv = av, var.path = NULL;
	var.concat = NULL, var.slash = NULL, var.status = 0, var.wcount = 1;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{

		if (_strcmp(line, "exit\n") == 0)
			free_exit(&var, line);
		if (_strcmp(line, "env\n") == 0)
			env_print(&var);
		_fork(&var, line, pid);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		var.wcount++;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);

	free(line);
	return (var.status);
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
	free(var->concat);
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
}

