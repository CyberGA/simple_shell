#include "shell.h"
/**
 * _strcpy - a function that copies the string pointed to by src
 * @buff2: string to copy a string
 * @buff: string to be copied from
 * Return: a pointer to buff2
 */
char *_strcpy(char *buff2, char *buff)
{
	int j = 0;

	while (buff[j] != '\0')
	{
		buff2[j] = buff[j];
		j++;
	}
	buff2[j] = '\0';
	return (buff2);
}
/**
 * _strlen - a function that returns the length of a string.
 * @s: character to be checked
 * Return: 0
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
/**
 * _strcat -  a function that concatenates two strings.
 * @buff2: pointer to be checked
 * @buff: pointer to be checked
 * Return: Value of pointer
 */
char *_strcat(char *buff2, char *buff)
{
	char *ptr = buff2;

	while (*buff2 != '\0')
	{
		buff2++;
	}
	while (*buff != '\0')
	{
		*buff2 = *buff;
		buff2++;
		buff++;
	}
	*buff2 = '\0';
	return (ptr);
}
/**
 * _strcmp - a function that compares two strings
 * @str1:string to be checked
 * @str2: string to be checked
 * Return: 0 positive or negative
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (*str1 - *str2);
	}
	return (0);
}
