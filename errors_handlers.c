#include "shell.h"

/**
 * end_of_file - function to handle end of file
 * @buffer: buffer to store input
 * @charRead: number of characters read
 * Return: nothing
 */
void end_of_file(char *buffer, ssize_t charRead)
{
	if (charRead == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
}
