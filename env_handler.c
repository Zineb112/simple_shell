#include "shell.h"

/**
 * my_path - function that print envment PATH
 * @env: envment variable
 * @xfirst: first splite into tokns with inptted args
 * @inpt:   input is split into tokens
 * @exit_st:   exit status
 * Return: 0
 */
int my_path(char *xfirst, char **inpt, char **env, int *exit_st)
{
	int i;
	char *temp, *p_left, *p_right;
	char *new = NULL, *env_cp = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		env_cp = str_dup(env[i]);
		p_left = strtok(env_cp, "= \t");
		temp = strtok(NULL, "= \t");

		if (str_cmp(p_left, "PATH") == 0)
		{
			p_right = strtok(temp, ": \t");
			while (p_right)
			{
				new = path_str(p_right, xfirst);

				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
						execve(new, inpt, NULL);

					else
						wait(NULL);
					*exit_st = 0;
					free(new);
					free(env_cp);
					return (0);
				}
				p_right = strtok(NULL, ": \t");
				free(new);
			}
		}
		free(env_cp);
	}
	return (2);
}

/**
 * print_env - print env variable
 * @env:   env variable to print
 * @exit_st: exit status
 * Return:  0 is succes
 */
int print_env(char **env, int *exit_st)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		printstr_(env[i]);
		put_char('\n');
		i++;
	}
	*exit_st = 0;
	return (EXIT_SUCCESS);
}

