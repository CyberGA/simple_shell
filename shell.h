#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *_strcpy(char *buff2, char *buff);
int _strlen(char *s);
char *_strcat(char *buff2, char *buff);
void execmd(char **argv);
char *fileLocation(char *linCom);
int _strcmp(char *str1, char *str2);

#endif /*SHELL.H*/
