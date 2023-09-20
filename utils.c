#include "shell.h"

/**
 * arr_cleaner - a function that free an array of strings
 * @strArr: pointer to array
 */
void arr_cleaner(char **strArr)
{
	int i = 0;

	while (strArr[i] != NULL)
	{
		free(strArr[i]);
		i++;
	}
	free(strArr);
	strArr = NULL;
}

/**
 * is_delimiter - a function that checks a char is a
 * delimiter
 * @c: character to check for
 * @delimiter: delimiter string
 * Return: 1 if a delimiter, 0 if not
 */
int is_delimiter(char c, const char *delimiter)
{
	int i = 0;

	while (delimiter[i] != '\0')
	{
		if (c == delimiter[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strdup - a function that duplicates a string
 * @originalString: string to be duplicated
 * Return: duplicated string
 */
char *_strdup(const char *originalString)
{
	size_t len;
	char *dup;

	len = strlen(originalString);
	dup = (char *)malloc((len + 1) * sizeof(char));

	if (dup != NULL)
	{
		_strcpy(dup, (char *)originalString);
	}
	return (dup);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
