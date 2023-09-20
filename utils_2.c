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
