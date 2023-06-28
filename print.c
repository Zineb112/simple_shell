#include "shell.h"

/**
 * put_char - write char ch in stdout
 * @ch:  a char to print
 * Return: if success return 1.if error, -1
 */
int put_char(char ch)
{
	return (write(1, &ch, 1));
}


/**
 * printstr_ - prints string
 * @st: string to be printed
 * Return: void
 */
void printstr_(char *st)
{
	int i, byt, w;

	for (i = 0; st[i] != '\0'; i++)
		;

	byt = i;

	w = write(STDOUT_FILENO, st, byt);
	if (w == EOF)
		return;
}


/**
 * path_str - function that prints   path string
 * @p_right: string after "PATH ="
 * @xfirst: first tokenized word
 * Return: 0 for success
 */
char *path_str(char *p_right, char *xfirst)
{
	char *new = NULL;
	char *token = NULL;
	int token_len = 0, xfirst_len = 0;

	token = p_right;
	token_len = str_len(token);
	xfirst_len = str_len(xfirst);

	new = malloc((token_len + xfirst_len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);

	new[0] = '\0';

	str_cat(new, p_right);
	str_cat(new, "/");
	str_cat(new, xfirst);
	str_cat(new, "\0");

	return (new);
}

/**
 * print_int - prints  int
 * @tally: pointer to tally nbr
 * Return: void
 */
void print_int(int *tally)
{
	int cnt = 0, lent = 0, j, nb;
	unsigned int base = 1, dd, max;

	nb = *tally;

	max = nb;
	dd = max;

	do {
		dd /= 10;
		++lent;
	} while (dd != 0);

	cnt += lent;

	for (j = 0; j < lent -  1; j++)
		base = base * 10;

	put_char('0' + (max / base));

	if (lent > 1)
	{
		for (j = 0; j < lent - 2; j++)
		{
			base /= 10;
			dd = max / base;
			put_char('0' + dd % 10);
		}
		put_char('0' + (max % 10));
	}
}


/**
 * _parser - function takes string  frm command line,returns  string
 *  using  space as  delim
 * @l: Charter pter storing user inpt
 * Return: char pointers contain an arg
 *
 */

char **_parser(char *l)
{
	char **args;

	char *parss = NULL;
	char *parss2 = NULL;
	char *lin_cp = NULL;

	int arg_num = 0, i = 0;

	lin_cp = str_dup(l);
	parss = strtok(lin_cp, " \t");

	while (parss != NULL)
	{
		arg_num++;
		parss = strtok(NULL, " \t");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parss2 = strtok(l, " \t");

	while (parss2 != NULL)
	{
		args[i] = parss2;
		parss2 = strtok(NULL, " \t");
		i++;
	}

	args[i] = NULL;
	free(lin_cp);
	return (args);
}

