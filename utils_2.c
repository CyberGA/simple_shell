#include "shell.h"
/**
 * _trimbuff - a function that removes
 * extra spaces from a string
 * @str: string to be trimmed
 */
void _trimbuff(char *str)
{
	int i = 0, k, j = _strlen(str) - 1;

	while (str[i] == ' ')
		i++;

	while (str[j] == ' ')
		j--;

	for (k = 0; k <= j - i; k++)
		str[k] = str[i + k];

	str[j - i + 1] = '\0';
}

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
 * _strncpy - a function that copies a string
 * @dest: a pointer to copy a string
 * @src: a pointer to be copied from
 * @n: a number to be passed and checked
 * Return: Value of dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strncmp - a function that compares two strings
 * @s1: first string for comparison
 * @s2: second string for comparison
 * @n: length of the characters to compare in bytes
 * Return: 0 or 1
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * getPATH - a function to retrieve the value of the PATH environment variable
 * @path: pointer to a buffer to store the PATH value
 * @maxLength: maximum length of the buffer
 * Return: the path value
 */
char *getPATH(char *path, size_t maxLength)
{
	char *env = NULL;
	size_t i = 0;

	path[0] = '\0';
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			env = environ[i] + 5;
			_strncpy(path, env, maxLength - 1);
			path[maxLength - 1] = '\0';
			return (path);
		}
	}
	return (NULL);
}
