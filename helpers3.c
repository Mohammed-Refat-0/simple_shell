#include "main.h"
/**
 * mystrdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to copy to the new allocated space
 * Return: char pointer
 */
char *mystrdup(const char *str)
{
	int j;
	int i = 0;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	ptr = (char *) malloc((i + 1) * sizeof(char));
	if (!ptr)
	{
		return (NULL);
	}
	for (j = 0; j < i ; j++)
	{
		ptr[j] = str[j];
	}
	ptr[i] = '\0';
	return (ptr);
}
/**
 * _cutline - cut newline char form char ptr
 * @ptr: ptr to cut from
 * Return: void
 */
void _cutline(char *ptr)
{
	int i = 0;

	if (!ptr)
	{
		return;
	}
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
		{
			ptr[i] = '\0';
		}
		i++;
	}
}
/**
 * mygetenv - return ptr to str ,if str is found in environ
 * @str: ptr to search for in environ
 * Return: char * if found, null otherwise
 */
char *mygetenv(const char *str)
{
	int j = 0;
	int i = 0;
	const char *ptr = str;
	int check = 0;
	int len = mystrlen(str);

	if (!str)
	{
		return (NULL);
	}
	while (environ[i] != NULL)
	{
		j = 0;
		check = 0;
		while (ptr[j] != '\0' && environ[i][j] != '=' && ptr[j] == environ[i][j])
		{
			j++;
			check++;
		}
		if (ptr[j] == '\0' && environ[i][j] == '=' && check == len)
		{
			return (&environ[i][j + 1]);
		}
		i++;
	}
	return (NULL);
}
/**
 * printprompt - printprompt
 * Return: void
 */
void printprompt(void)
{
	char *prompt = "#";
	int i = 0;

	while ((prompt[i]) != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}
}
