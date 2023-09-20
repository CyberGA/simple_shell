#include "shell.h"

/**
 * clear_mem - clear memory
 * @argv: command line arguments
 * @buffer: pointer to buffer
 * @buffer2: pointer to buffer2
 */
void clear_mem(char **argv, char *buffer, char *buffer2)
{
	free(buffer);
	free(buffer2);
	arr_cleaner(argv);
}
/**
 * exit_with_status - a function that exit with status
 * @count: number or shell args
 * @comp: 0 if exit, 1 if not
 * @argv: pointer to shell args
 * @buffer: string memory to be freed
 * @buffer2: string memory needed to be freed
 * Return: negative if exit status is not recognized
 */
void exit_with_status(size_t count, int comp, char **argv,
		char *buffer, char *buffer2)
{
	int status = 0;

	if (count == 1 && comp == 0)
	{
		clear_mem(argv, buffer, buffer2);
		exit(status);
	}
	else if (count > 1 && comp == 0)
	{

		if (argv[1][0] > '9' || argv[1][0] < '0')
		{
			write(STDERR_FILENO, "./hsh: 1: ", 10);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);
			clear_mem(argv, buffer, buffer2);
			exit(STDERR_FILENO);
		}
		status = atoi(argv[1]);
		clear_mem(argv, buffer, buffer2);
		exit(status);
	}
}
/**
 * get_cmd - function to get command
 * @split: pointer to split
 * @c: size_t c
 * @buffer: pointer to buffer
 * @buffer2: pointer to buffer2
 * Return: argv
 */
char **get_cmd(char *split,
		size_t c,
		char *buffer, char *buffer2)
{
	char **argv = NULL;
	int comp, i;
	size_t count = c;
	const char *delim = " \n,'";

	split = _strtokenizer(buffer, delim);
	while (split != NULL)
	{
		count++;
		split = _strtokenizer(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (count + 1));
	if (argv == NULL)
	{
		free(buffer);
		free(buffer2);
		exit(EXIT_FAILURE);
	}
	split = _strtokenizer(buffer2, delim);
	for (i = 0; split != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(split) + 1));
		if (argv[i] == NULL)
		{
			free(buffer);
			free(buffer2);
			exit(EXIT_FAILURE);
		}
		_strcpy(argv[i], split);
		split = _strtokenizer(NULL, delim);
	}
	argv[i] = NULL;
	comp = _strcmp(argv[0], "exit");
	exit_with_status(count, comp, argv, buffer, buffer2);
	return (argv);
}

