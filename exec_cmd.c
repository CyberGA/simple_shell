#include "shell.h"
/**
 * execmd - a function to handle command execution
 * @argv: list of argument variabes
 * @envp: list of environment variables
 * @buffer: string memory to be freed
 * @buffer2: string memory needed to be freed
 * Return: nothing
 */
void execmd(char **argv, char **envp, char *buffer, char *buffer2)
{
	char *execute = NULL, *findPath = NULL, *filePath = NULL;
	pid_t childPid;
	int stat;

	if (argv)
	{
		execute = argv[0];
		findPath = fileLocation(execute, filePath);
		if (findPath != NULL)
		{
			childPid = fork();
			if (childPid == 0)
				execve(findPath, argv, envp);
			else if (childPid == -1)
				exit(1);
			else
			{
				wait(&stat);
				if (WEXITSTATUS(stat) == 2)
				{
					clear_mem(argv, buffer, buffer2);
					free(findPath);
					exit(WEXITSTATUS(stat));
				}
			}
			free(findPath);
		}
		else
		{
			clear_mem(argv, buffer, buffer2);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		write(STDERR_FILENO, "Invalid command\n", 17);
		exit(EXIT_FAILURE);
	}
}
