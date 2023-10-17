#include "main.h"
/**
 * checkwait - validate wait
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkwait(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("wait");
	_putchar('\n');
	_exit(1);
}
/**
 * checkchild - validate child process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkchild(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror("fork");
	_putchar('\n');
	_exit(1);
}
/**
 * checkexecve - validate execve process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * Return: void
 */
void checkexecve(char **argv, char *linecpy, list_t *head,
char *lineptr, int count)
{
	freelinecpy(linecpy);
	free_list(head);
	freelineptr(lineptr);
	freeargv(argv, count);
	perror(NULL);
	_putchar('\n');
	_exit(1);
}
/**
 * execute - execute the process
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @count: no of elements
 * @status: status of wait
 * Return: void
 */
void execute(char **argv, char *linecpy, list_t *head,
char *lineptr, int count, int status)
{
	pid_t child;

	if (mystrcmp(argv[0], "exit") == 0)
	{
		exitshell(argv, linecpy, head, lineptr, count);
	}
	else if (mystrcmp(argv[0], "env") == 0)
	{
		myenv(environ);
	}
	else
	{
		if (argv[0] != NULL)
		{
			child = fork();
			if (child == -1)
			{
				checkchild(argv, linecpy, head, lineptr, count);
			}
			if (child == 0)
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					checkexecve(argv, linecpy, head, lineptr, count);
				}
			}
			else
			{
				if (wait(&status) == -1)
				{
					checkwait(argv, linecpy, head, lineptr, count);
				}
			}
		}
	}
}
/**
 * commandhandling - parse the command
 * @argv: array of strings
 * @linecpy: copied line ptr
 * @head: pointer to head of linked list
 * @lineptr: ptr to line
 * @ptrcount: no of elements
 * @delim: delim to parse command by
 * @token: ptr
 * @size: size
 * Return: void
 */
void commandhandling(char **argv, char *lineptr, char *linecpy,
list_t *head, int *ptrcount, const char  *delim, char *token, int size)
{
	int i = 0;
	int count = *ptrcount;

	if (linecpy)
	{
		free(linecpy);
		linecpy = NULL;
	}
	if (argv)
	{
		freeargv(argv, count);
		argv = NULL;
	}
	count = 0;
	linecpy = mystrdup(lineptr);
	checklinecpy(linecpy, head, lineptr);
	_cutline(linecpy);
	token = strtok(linecpy, delim);
	argv = malloc(sizeof(char *) * (size));
	checkargv(argv, linecpy, head, lineptr, *ptrcount);
	while (token != NULL)
	{
		argv[i] = mystrdup(token);
		if (argv[i] == NULL)
		{
			checkargvelement(argv, linecpy, head, lineptr, *ptrcount);
		}
		token = strtok(NULL, delim);
		(*ptrcount)++;
		i++;
	}
	argv[*ptrcount] = NULL;
}
