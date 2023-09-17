#include "shell.h"

/**
 * _myGetline - a function that reads an entire line from stream
 * @lineptr: pointer to lineptr
 * @n: size_t n
 * @stream: pointer to stream
 * Return: length of lineptr
 */

int _myGetline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[128];
	size_t length = 0, i = 0;
	ssize_t charRead;
	char *temp = NULL;

	if (*lineptr == NULL)
	{
		*n = 128;
		*lineptr = (char *)malloc(sizeof(char *) * (*n));
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		if (length >= (*n - 1))
		{
			*n *= 2;
			temp = (char *)realloc(*lineptr, *n);
			if (temp == NULL)
			{
				free(*lineptr);
				exit(1);
			}
			*lineptr = temp;
		}
		charRead = read(fileno(stream), &buffer[i], 1);
		if (charRead == -1 || (charRead == 0 && length == 0))
			return (-1);
		if (charRead == 0 || buffer[i] == '\n')
		{
			(*lineptr)[length] = '\0';
			return (length);
		}
		(*lineptr)[length] = buffer[i];
		length++;
		i++;
	}
	return (length);
}
