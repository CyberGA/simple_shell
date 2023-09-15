#include "shell.h"
/**
 * execmd - a function to handle command execution
 * @argv: list of argument variabes
 * @envp: list of environment variables
 * Return: nothing
 */
void execmd(char **argv, char **envp)
{
	char *execute = NULL, *findPath = NULL;
	pid_t childPid;
	int stat;

	if (argv)
	{
		execute = argv[0];
		findPath = fileLocation(execute);
		if (findPath != NULL)
		{
			childPid = fork();
			if (childPid == 0)
			{
				if (execve(findPath, argv, envp) == -1)
				{
					write(2, " 1: qwerty: not found ", 22);
					write(2, "\n", 1);
				}
			}
			else if (childPid == -1)
				exit(1);
			else
				wait(&stat);
		}
		else
		{
			write(2, "qwerty: not found\n", 18);
		}
	}
	else
	{
		write(2, "Invalid command\n", 16);
		exit(1);
	}
}
