#include "shell.h"
/**
 * get_path - generate the path for each command
 * @pathToken: pointer to pathToken
 * @linCom: command line argument
 * @path2: pointer to path2
 * @lenOfCommand: size_t lenOfCommand
 * @buff: struct stat buff
 * @filePath: pointer to filePath
 * Return: char
 */
char *get_path(char *pathToken, char *linCom, char *path2,
		size_t lenOfCommand, stat_t buff, char *filePath)
{
	size_t lenOfToken;

	if (stat(linCom, &buff) == 0)
	{
		free(path2);
		lenOfToken = _strlen(linCom);
		filePath = malloc(lenOfCommand + lenOfToken + 2);
		if (filePath == NULL)
			return (NULL);
		_strcpy(filePath, linCom);
		return (filePath);
	}
	while (pathToken != NULL)
	{
		lenOfToken = _strlen(pathToken);
		filePath = malloc(lenOfCommand + lenOfToken + 2);
		if (filePath == NULL)
		{
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
			pathToken = _strtokenizer(NULL, ":");
			free(filePath);
		}
	}
	free(path2);
	return (NULL);
}
