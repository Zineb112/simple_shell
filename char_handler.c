#include "shell.h"

/**
 * grid_free -  free grid of int ptrs
 * @gridd: Char double ptr freed
 * @_height: int for height to be passed
 * Return: void
 */

void grid_free(char **gridd, int _height)
{
	int k;

	for (k = 0; k < _height; k++)
		free(gridd[k]);

	free(gridd);
}


/**
 * no_nul - remov  new line using NULL char
 * @l:   c_lin
 * Return: nothing
 */
void no_nul(char *l)
{

	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';
			return;
		}

		i++;
	}
}


/**
 * char_special - exits   shell and handles
 * @byt:   nbr of byt read from  inpt
 * @buffer:   buffer char
 * @exit_st:   exit status
 * Return: 0 succces
 */
int  char_special(char *buffer, ssize_t byt, int *exit_st)
{
	int i = 0;

	if (byt == EOF && isatty(STDIN_FILENO) == 1)
	{
		put_char('\n');
		free(buffer);
		exit(*exit_st);
	}

	if (byt == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*exit_st);
	}

	if (str_cmp(buffer, "\n") == 0)
	{
		*exit_st = 0;
		return (127);
	}

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	*exit_st = 0;
	return (127);
}

