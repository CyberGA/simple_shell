#include "shell.h"
/**
 * fileLocation - generate the path for each command
 * @linCom: command line argument
 * Return: char
 */
char *fileLocation(char *linCom)
{
	char *path, *path2;
	size_t lenOfCommand, lenOfToken;
	char *pathToken, *filePath;
	struct stat buff;

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
		while (pathToken != NULL)
		{
			lenOfToken = _strlen(pathToken);
			filePath = malloc(lenOfCommand + lenOfToken + 2);
			if (filePath == NULL)
			{
				perror("malloc error!");
				free(path2);
				return (NULL);
			}
			_strcpy(filePath, pathToken);
			_strcat(filePath, "/");
			_strcat(filePath, linCom);
			_strcat(filePath, "\0");
			if (stat(filePath, &buff) == 0)
			{
				free(path2);
				return (filePath);
			}
			else
			{
				free(filePath);
				pathToken = strtok(NULL, ":");
			}
		}
		free(path2);
		if (stat(linCom, &buff) == 0)
		{
			return (linCom);
		}
		return (NULL);
	}
	else
	{
		write(2, "PATH env. variable not set\n", 27);
		return (NULL);
	}
	return (NULL);
}
