#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct stat stat_t;

void end_of_file(char *, ssize_t);
char *_strcpy(char *buff2, char *buff);
int _strlen(char *s);
char *_strcat(char *buff2, char *buff);
void execmd(char **argv, char **envp);
char *fileLocation(char *linCom, char *);
int _strcmp(char *str1, char *str2);
char **get_cmd(char *, size_t, char *, char *);
char *get_path(char *, char *, char *, size_t,
		stat_t, char *);
int _emptystr(char *buffer);
int _myGetline(char **lineptr, size_t *n, FILE *stream);
char *_strtokenizer(char *, const char *);
void arr_cleaner(char **strArr);
int is_delimiter(char, const char *);
void processSetenv(char *variable, char *value);
void processUnsetenv(char *variable);

#endif /*SHELL.H*/
