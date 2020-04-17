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

/**
 * _fork - fork the process to work in child pid
 * @var: global structure
 * @line: buffer that contains the getline buff
 * @pid: is the pid proccess
 * Return: zero.
 */

int _fork(stva *var, char *line, pid_t pid)
{
	if (line[0] == '\n' || (line[0] == ' ' && line[1] != ' ') || line[0] == '\t')
		write(STDOUT_FILENO, "evilshell$ ", 11);
	else
	{
		if (tokensfun(var, line) == 0)
			return (5);
		if (var->tok[0] == NULL || (var->tok[0][0] == '.' && var->tok[0][1] != '/'))
		{
			free(var->tok);
			write(STDOUT_FILENO, "evilshell$ ", 11);
			return (0);
		}
		execute(var);

		pid = fork();
		if (pid == -1)
		{ perror("Error:");
			exit(EXIT_FAILURE); }
		if (pid == 0)
		{
			concatenate(var);
			if (var->concat == NULL)
			{ free(var->tok), free(var->pathtok), free(var->path);
				return (1); }
			else if (var->status == 0)
			{ execve(var->concat, var->tok, NULL);
				exit(0); }
		}
		else
		{
			wait(&pid);
			free(var->concat);
		}
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
	stva var;

	var.tok = NULL, var.pathtok = NULL, var.argv = av, var.path = NULL;
	var.concat = NULL, var.status = 0, var.wcount = 1;
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "evilshell$ ", 11);
	signal(SIGINT, sig_handler);
	while ((character = getline(&line, &size, stdin)) != EOF)
	{
		int tmp;

		if (_strcmp(line, "exit\n") == 0)
			free_exit(&var, line);

		tmp = _fork(&var, line, pid);

		if (tmp == 1)
			break;
		else if (tmp == 5)
		{
			write(STDOUT_FILENO, "evilshell$ ", 11);
			continue;
		}

		var.wcount++;
	}
	return (free(line), var.status);
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


}
