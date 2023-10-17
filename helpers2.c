#include "main.h"
/**
 * freelinecpy -  function that frees char pointer.
 * @linecp: a pointer to free
 * Return: 0
 */
int freelinecpy(char *linecp)
{
	if (linecp)
	{
		free(linecp);
	}
	return (0);
}
/**
 * freelineptr -  function that frees char pointer.
 * @lineptr: a pointer to free
 * Return: 0
 */
int freelineptr(char *lineptr)
{
	if (lineptr)
	{
		free(lineptr);
	}
	return (0);
}
/**
 * freeargv -  function that frees array of strings argv.
 * @argv: a pointer to array
 * @size: size of array to free
 * Return: 0
 */
int freeargv(char **argv, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (argv[i] != NULL)
		{
			free(argv[i]);
		}
	}
	if (argv != NULL)
	{
		free(argv);
		argv = NULL;
	}
	return (0);
}
/**
 * mystrlen - return length of string
 * @s: string to evalute
 * Return: length of string
 */
int mystrlen(const char *s)
{
	int length = 0;

	if (!s)
	{
		return (0);
	}
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
/**
 * mystrcmp - compare two strings
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * Return: 0, 1 0r -1
 */
int mystrcmp(const char *s1, const char *s2)
{
	int length = 0;

	if (!s1 || !s2)
	{
		return (-1);
	}
	while (s1[length] != '\0' && s2[length] != '\0')
	{
		if (s1[length] != s2[length])
		{
			return (s1[length] - s2[length]);
		}
		length++;
	}

	if (s1[length] != '\0' && s2[length] == '\0')
	{
		return (1);
	}
	else if (s1[length] == '\0' && s2[length] != '\0')
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}
