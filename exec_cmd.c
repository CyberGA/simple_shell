#include "shell.h"
/**
 * execmd - a function to handle command execution
 * @argv: list of argument variabes
 * Return: nothing
 */
void execmd(char **argv)
{
	char *execute = NULL;
	char *findPath = NULL;

	if (argv)
	{
		execute = argv[0];
		findPath = fileLocation(execute);
		if (findPath != NULL)
		{
			if (execve(findPath, argv, NULL) == -1)
			{
				write(2, " 1: qwerty: not found ", 22);
				/*write(2, execute, _strlen(execute));*/
				write(2, "\n", 1);
				exit(1);
			}
		}
		else
		{
			write(2, "qwerty: not found\n", 18);
			exit(1);
		}
	}
	else
	{   
		write(2, "Invalid command\n", 16);
		exit(1);
	}
}
