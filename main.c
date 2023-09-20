#include "shell.h"
/**
 * main - function to build a simple shell
 * @argc: number of arguments
 * @argv: pointer to arguments
 * @envp: pointer to environment variables
 * Return: 0 or 1 or otherwise
 */
int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char **argv, char **envp)
{
	size_t n = 0;
	char *buffer = NULL, *split = NULL, *buffer2 = NULL;
	ssize_t charRead;
	char **args = NULL;

	while (1)
	{
		charRead = _myGetline(&buffer, &n, stdin);
		end_of_file(buffer, charRead);
		if (_emptystr(buffer) == 1)
			continue;
		_trimbuff(buffer);
		buffer2 = malloc(sizeof(char) * charRead + 1);
		if (buffer2 == NULL)
		{
			perror("Mem. allocation failed");
			free(buffer);
			return (-1);
		}
		_strcpy(buffer2, buffer);
		args = get_cmd(split, 0, buffer, buffer2);
		execmd(args, envp);
		arr_cleaner(args);
		free(buffer2);
	}
	free(buffer);
	return (0);
}
