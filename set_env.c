#include "shell.h"
/**
 * processSetenv - a function to set env. variables
 * @variable: name of variable to set
 * @value: value of variable to be set
 */
void processSetenvCommand(char *variable, char *value);

void processSetenv(char *variable, char *value)
{
	char setenvPath[MAX_PATH_LEN], *pathHolder;
	int setResult;

	pathHolder = getPATH(setenvPath, MAX_PATH_LEN);
	if (pathHolder != NULL)
		setResult = setenv(variable, value, 1);
	else
		setResult = setenv(variable, value, 0);
	if (setResult == -1)
		perror("Error in setenv!");
}
/**
 * processUnsetenv - a function to unset env. variables
 * @variable: variable to unset
 */
void processUnsetenv(char *variable)
{
	char unsetenvPath[MAX_PATH_LEN], *pathHolder;
	int unsetResult;

	pathHolder = getPATH(unsetenvPath, MAX_PATH_LEN);
	if (pathHolder != NULL)
	{
		unsetResult = unsetenv(variable);
		if (unsetResult == -1)
			perror("Error in unsetenv");
	}
	else
	{
		/* Handle case where variable doesn't exist */
	}
}
/**
 * processSetenvCommand - a function to set and unset env. variables
 * @variable: name of variable to set or unset
 * @value: value of variable to be set
 */
void processSetenvCommand(char *variable, char *value)
{
	size_t length = 0;
	ssize_t read;
	char *buffer = NULL;
	char *setenvCom;

	read = _myGetline(&buffer, &length, stdin);
	if (read != -1)
	{
		setenvCom = _strtokenizer(buffer, " ");
		variable = _strtokenizer(NULL, " ");
		value = _strtokenizer(NULL, " ");
		if (setenvCom != NULL && variable != NULL && value != NULL)
		{
			if (_strcmp(setenvCom, "setenv") == 0)
			{
				processSetenv(variable, value);
			}
			else if (_strcmp(setenvCom, "unsetenv") == 0)
			{
				processUnsetenv(variable);
			}
			else
				write(2, "Invalid command\n", 16);
		}
		else
		{
			write(2, "Invalid input: Provide both variable and value\n", 47);
		}
	}
	else
	{
		write(2, "Error reading input\n", 20);
	}
	free(buffer);
}

