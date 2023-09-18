#include "shell.h"
/**
 * fileLocation - generate the path for each command
 * @linCom: command line argument
 * @filePath: filePath of the arg
 * Return: char
 */
char *fileLocation(char *linCom, char *filePath)
{
	char *path = NULL, *path2 = NULL;
	size_t lenOfCommand;
	char *pathToken = NULL;
	stat_t buff;

	path = getenv("PATH");
	if (path)
	{
		path2 = _strdup((const char *)path);
		if (path2 == NULL)
		{
			perror("strdup");
			return (NULL);
		}
		lenOfCommand = _strlen(linCom);
		pathToken = _strtokenizer(path2, ":");
		return (get_path(pathToken, linCom, path2, lenOfCommand, buff, filePath));
	}
	else
	{
		write(2, "PATH env. variable not set\n", 27);
		return (NULL);
	}
	return (NULL);
}
