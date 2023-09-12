#include "shell.h"
/**
 * fileLocation - generate the path for each command
 * @linCom: command line argument
 * Return: char
 */
char *fileLocation(char *linCom)
{
	char *path = NULL, *path2 = NULL;
	size_t lenOfCommand;
	char *pathToken = NULL, *filePath = NULL;
	stat_t buff;

	path = getenv("PATH");
	if (path)
	{
		path2 = strdup(path);
		if (path2 == NULL)
		{
			perror("strdup");
			return (NULL);
		}
		lenOfCommand = _strlen(linCom);
		pathToken = strtok(path2, ":");
		return (get_path(pathToken, linCom, path2, lenOfCommand, buff, filePath));
	}
	else
	{
		write(2, "PATH env. variable not set\n", 27);
		return (NULL);
	}
	return (NULL);
}
