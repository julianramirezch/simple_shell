#include "shell.h"

/**
 * sig_handler - signal handler for ctrl + c
 * @signum: signalnumber
 * Return: none.
 */
void sig_handler(int signum)
{
	if (signum == 2)
		write(STDOUT_FILENO, "\nevilshell$ ", 12);
}

int test(stva *var, char *line, pid_t pid, struct stat st)
{
	//(void) pid;
	(void) st;
	if (line[0] == '\n' || (line[0] == ' ' && line[1] != ' ') || line[0] == '\t')
		write(STDOUT_FILENO, "evilshell$ ", 11);
	else if (line[0] == '.' && line[1] == ' ')
		write(STDOUT_FILENO, "evilshell$ ", 11);
	else if (_strcmp(line, "exit\n") != 0)
		free_exit(var, line);
	else
	{
		tokensfun(var, line);
		if (var->tok[0] == NULL || strcmp(var->tok[0], ".") == 0)/* ARREGAL */
		{
			free(var->tok);
			write(STDOUT_FILENO, "evilshell$ ", 11);
			return(0);
		}
		execute(var);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (var->concat == NULL)
			{
				free(var->tok), free(var->pathtok), free(var->path);
				return (1);
			}
			else if (var->status == 0)
				execve(var->concat, var->tok, NULL);
		}
		else
		wait(&pid);
		write(STDOUT_FILENO, "evilshell$ ", 11), free_st(var);
	}
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
	struct stat st;
	stva var;

	var.tok = NULL, var.pathtok = NULL, var.argv = av, var.path = NULL;
	var.concat = NULL, var.status = 0, var.wcount = 1;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "evilshell$ ", 11);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{
		if (_strcmp(line, "exit\n") != 0)
			free_exit(&var, line);
		if (test(&var, line, pid, st) == 1)
			break;
		var.wcount++;
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

/**
 * free_exit - functions that free in exit commands
 * @var: global structure
 * @line: Pointer to line
 * Return: none
 */
void free_exit(stva *var, char *line)
{
	if (var->wcount == 1)
		free(line);
	else
	{
		free(line);
	 	//free(var->pathtok);
		//free(var->path);
	}
	exit(var->status);
}
