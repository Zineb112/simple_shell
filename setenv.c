#include "shell.h"

/**
 * get_env -  give the  value of  global variable
 * @glob_v: glob_value of the global var
 * Return: string
 */
char *get_env(const char *glob_v)
{
	int i, m;
	char *valeur;

	if (!glob_v)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		m = 0;
		if (glob_v[m] == environ[i][m])
		{
			while (glob_v[m])
			{
				if (glob_v[m] != environ[i][m])
					break;

				m++;
			}
			if (glob_v[m] == '\0')
			{
				valeur = (environ[i] + m + 1);
				return (valeur);
			}
		}
	}
	return (0);
}

/**
 * concatenat - concats three strings in new allocation memo
 * @glob_v: first string input
 * @valeur1: second string input
 * @valeur: Third string input
 * Return: pointer to the new string
 */
char *concatenat(char *glob_v, char *valeur1, char *valeur)
{
	char *result;
	int len1, len2, len3, i, w;

	len1 = str_len(glob_v);
	len2 = str_len(valeur1);
	len3 = str_len(valeur);

	result = malloc(len1 + len2 + len3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; glob_v[i]; i++)
		result[i] = glob_v[i];
	w = i;

	for (i = 0; valeur1[i]; i++)
		result[w + i] = valeur1[i];
	w = w + i;

	for (i = 0; valeur[i]; i++)
		result[w + i] = valeur[i];
	w = w + i;

	result[w] = '\0';

	return (result);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arr: array of entered words
 */
void _setenv(char **arr)
{
	int i, m, w;

	if (!arr[1] || !arr[2])
	{
		perror(get_env("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		m = 0;
		if (arr[1][m] == environ[i][m])
		{
			while (arr[1][m])
			{
				if (arr[1][m] != environ[i][m])
					break;

				m++;
			}
			if (arr[1][m] == '\0')
			{
				w = 0;
				while (arr[2][w])
				{
					environ[i][m + 1 + w] = arr[2][w];
					w++;
				}
				environ[i][m + 1 + w] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = concatenat(arr[1], "=", arr[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _unsetenv - Remove an environment variable
 * @arr: array of entered words
 */
void _unsetenv(char **arr)
{
	int i, m;

	if (!arr[1])
	{
		perror(get_env("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		m = 0;
		if (arr[1][m] == environ[i][m])
		{
			while (arr[1][m])
			{
				if (arr[1][m] != environ[i][m])
					break;

				m++;
			}
			if (arr[1][m] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

