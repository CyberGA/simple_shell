#include "shell.h"

/**
 * fileLocation - generate the path for each command
 * @linCom: command line argument
 * @filePath: filePath of the arg
 * Return: char
 */
char *fileLocation(char *linCom, char *filePath)
{
	char path[MAX_PATH_LEN], *path2 = NULL;
	size_t lenOfCommand;
	char *pathToken = NULL;
	stat_t buff;
	char *pathHolder, *result;

	pathHolder = getPATH(path, MAX_PATH_LEN);
	if (pathHolder)
	{
		path2 = _strdup((const char *)path);
		if (path2 == NULL)
		{
			perror("strdup");
			return (NULL);
		}
		lenOfCommand = _strlen(linCom);
		pathToken = _strtokenizer(path2, ":");
		result = get_path(pathToken, linCom, path2, lenOfCommand, buff, filePath);
		return (result);
	}
	else
	{
		write(STDOUT_FILENO, environ[0], _strlen(environ[0]));
		write(STDOUT_FILENO, "\n", 1);
		if (environ[2] != NULL)
			write(STDOUT_FILENO, environ[2], _strlen(environ[2]));
		write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
}
