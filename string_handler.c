#include "shell.h"

/**
 * str_len - return lent of a str
 * @strg: string
 * Return: returns lent strg
 */
int str_len(char *strg)
{
	int j = 0;

	while (strg[j] != '\0')
		j++;

	return (j);
}



/**
 * str_cmp - comper strings.
 * @str1: first string.
 * @str2: second string.
 * Return: 0 if equal,otherwise other.
 */
int str_cmp(char *str1, char *str2)
{

	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}


/**
 * str_cpy - copy strg to anotherr
 * @dstn: string one
 * @sourc: string two
 * Return: string copied
 */
char *str_cpy(char *dstn, char *sourc)
{
	int a;

	for (a = 0; a <= str_len(sourc); a++)
		dstn[a] = sourc[a];
	return (dstn);
}


/**
 * str_dup - function returns ptr to a new allocatin contains a strg
 * given as a parameter
 * @strg: - Char strg to cpy
 * Return: Char ptr to   duplicated string. or NULL
 * if no memory
 */

char *str_dup(char *strg)
{
	char *dpstr;

	int i, l;

	if (strg == NULL)
		return (NULL);

	l = 0;

	for (i = 0; strg[i] != '\0'; i++)
		l++;

	dpstr = malloc(sizeof(char) * l + 1);

	if (dpstr == NULL)
		return (NULL);

	for (i = 0; i < l ; i++)
		dpstr[i] = strg[i];

	dpstr[l] = '\0';

	return (dpstr);

}


/**
 * str_cat - concat strgs
 * @dstn: strg nbr one
 * @sourc: string nbr two
 * Return: concat strg
 * with overwritten null byt
 */
char *str_cat(char *dstn, char *sourc)
{
	int len = str_len(dstn);
	int i;

	for (i = 0; sourc[i] != '\0'; i++)
		dstn[len + i] = sourc[i];
	dstn[len + i] = '\0';

	return (dstn);
}
