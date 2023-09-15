#include "shell.h"

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
	char **argv;
	char comp;
	size_t count = c;
	int i;
	const char *delim = " \n,'";

	split = _strtokenizer(buffer, delim);
	while (split != NULL)
	{
		count++;
		split = _strtokenizer(NULL, delim);
	}
	argv = malloc(sizeof(char *) * count + 1);
	split = _strtokenizer(buffer2, delim);
	for (i = 0; split != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(split) + 1);
		_strcpy(argv[i], split);
		split = _strtokenizer(NULL, delim);
	}
	argv[i] = NULL;
	comp = _strcmp(argv[0], "exit");
	if (count == 1 && comp == 0)
		exit(0);
	return (argv);
}
