#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <libgen.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

extern char **environ;

/**
 * struct var - global structure for shell project
 * @tok: gets tokens of prompt line
 * @pathtok: gets the tokens of PATH variable
 * @argv: arguments value of main function
 * @path: gets the enviroment variable PATH
 * @concat: gets path enviroment and command on one line
 * @status: gets the status to be returned
 * @wcount: count how many times run the prompt
 * Description: the var struct is a collection of variables used to
 * build in simple the project, passing arguments between functions easily
 */
typedef struct var
{
	char **tok;
	char **pathtok;
	char **argv;
	char *path;
	char *concat;
	int status;
	int wcount;
} stva;

/* free structure */
void free_st(stva *var);
/*---------------*/
void sig_handler(int signum);
void _getenv(stva *var, char *word);
void tokensfun(stva *var, char *line);
void _path(stva *var);
void execute(stva *var);
void commmand_not(stva *var, char *msg);
void concatenate(stva *var);
/* String functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
/*--------------------*/

#endif
