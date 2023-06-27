#include "shell.h"

/**
 * _getline - read string of text.
 * @line: dynamically allocated buffer.
 * @n: number of characters in the line.
 * @stream: the file to read from.
 * Return: number of characters read
 * and stored in the buffer.
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	size_t bf_size = 32;
	size_t nbr_char = 0;
	int c;
	char *temp;

	if (*line == NULL)
	{
		*line = malloc(bf_size * sizeof(char));
		if (*line == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (nbr_char >= bf_size - 1)
		{
			bf_size *= 2;
			temp = realloc(*line, bf_size * sizeof(char));

			if (temp == NULL)
			{
				perror("realloc failed");
				exit(EXIT_FAILURE);
			}
			*line = temp;
		}
		(*line)[nbr_char++] = (char)c;

		if (c == '\n')
			break;
	}
	if (nbr_char == 0)
		return (-1);

	(*line)[nbr_char] = '\0';
	*n = nbr_char;

	return (nbr_char);
}
