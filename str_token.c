#include "shell.h"

/**
 * _strtokenizer - a function to tokenize a string
 * @delimiter: string delimiter
 * @str: string to be tokenized
 * Return: delimited string
 */
char *_strtokenizer(char *str, const char *delimiter)
{

	static char *buffer;
	char *token = NULL;

	if (str)
	{
		buffer = str;
	}
	if (!buffer || !*buffer)
	{
		return (NULL);
	}

	token = buffer;

	while (*buffer && is_delimiter(*buffer, delimiter) == 0)
	{
		buffer += 1;
	}
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}

	return (token);
}
