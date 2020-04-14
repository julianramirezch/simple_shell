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

extern char **environ;

void sig_handler(int signum);
char *_getenv(char *line);
char **tokensfun(char *line);
char **_path(char *glres, char *delim);
char **tokensfun(char *line);
char *concatenate(char *string1, char *string2);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int commmand_not(char *com, char *arg, int cont, char *msg);
size_t count_direc(char **direct);

int (*built_in_check(char *ttk))();
void exit_func(char *line, char **ttk);
void freepathtokens(char **pathtokens);

#endif
