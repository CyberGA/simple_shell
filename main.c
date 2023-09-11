#include "shell.h"
/**
 * main - function to build a simple shell
 * Return: 0 or 1 or otherwise
 */
int main(void)
{
	size_t n = 0;
	char *buffer = NULL, *split;
	char *buffer2 = NULL, comp;
	const char *delim = " \n,'";
	ssize_t charRead;
	char **argv;
	size_t i, count;
	int stat;
	pid_t childPid;

	while (1)
	{
		count = 0;
		write(1, "$ ", 2);
		charRead = getline(&buffer, &n, stdin);
		if (charRead == -1)
		{
			write(1, "Bye from my shell....\n", 22);
			free(buffer);
			return (-1);
		}
		buffer2 = malloc(sizeof(char) * charRead + 1);
		if (buffer2 == NULL)
		{
			perror("Mem. allocation failed");
			free(buffer);
			return (-1);
		}
		_strcpy(buffer2, buffer);
		split = strtok(buffer, delim);
		while (split != NULL)
		{
			count++;
			split = strtok(NULL, delim);
		}
		printf("%ld\n", count);
		argv = malloc(sizeof(char *) * count + 1);
		split = strtok(buffer2, delim);
		for (i = 0; split != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(split) + 1);
			_strcpy(argv[i], split);
			/*write(1, argv[i], _strlen(split));
			  write(1, "\n", 1);*/
			split = strtok(NULL, delim);
		}
		argv[i] = NULL;
		comp = _strcmp(argv[0], "exit");
		if (count == 1 && comp == 0)
		{
			exit(0);
		}
		childPid = fork();
		if (childPid == 0)
		{
			execmd(argv);
		}
		else
		{
			wait(&stat);
		}
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(buffer2);
	}
	free(buffer);
	return (0);
}
