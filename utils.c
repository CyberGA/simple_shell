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