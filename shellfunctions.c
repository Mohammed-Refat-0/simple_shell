#include "main.h"
/**
 * checklist - validate created path
 * @head: pointer to head of linked list
 * Return: void
 */
void checklist(list_t *head)
{
	if (!head)
	{
		free_list(head);
		perror("create_path_list");
		_putchar('\n');
		exit(1);
	}
}
/**
 * checklinecpy - validate the coped line
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * Return: void
 */
void checklinecpy(char *linecpy, list_t *head, char *lineptr)
{
	if (!linecpy)
	{
		if (head)
		{
			free_list(head);
		}
		if (lineptr)
		{
			freelineptr(lineptr);
		}
		perror("mystrdup");
		_putchar('\n');
		exit(1);
	}
}
/**
 * checkargv - validate the arry of strings argv
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkargv(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	if (!argv)
	{
		freeargv(argv, count);
		freelinecpy(linecpy);
		free_list(head);
		freelineptr(lineptr);
		perror("malloc");
		_putchar('\n');
		exit(1);
	}
}
/**
 * checkargvelement - validate eleemnts
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkargvelement(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("mystrdup");
	_putchar('\n');
	exit(1);
}
/**
 * _exit - frees and exit
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void exitshell(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	if (linecpy)
	{
		freelinecpy(linecpy);
	}
	if (head)
	{
		free_list(head);
	}
	if (lineptr)
	{
		freelineptr(lineptr);
	}
	if (argv)
	{
		freeargv(argv, count);
	}
	exit(2);
}
