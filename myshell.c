#include "main.h"
/**
 * main - main function of the program "mysimpleshell"
 * Return: void
 */
int main(void)
{
	int count = 0, size = 1024, i = 0, status;
	char *lineptr = NULL, *linecpy = NULL, *token, *prompt = "#", **argv = NULL;
	const char *delim = " ";
	size_t n = 0;
	list_t *head;
	pid_t child;

	head = create_path_list();
	checklist(head);
	if (isatty(STDIN_FILENO) == 1)
	{
		while ((prompt[i]) != '\0')
		{
			_putchar(prompt[i]);
			i++;
		}
		while (getline(&lineptr, &n, stdin) != -1)
		{
			i = 0;
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
			checkargv(argv, linecpy, head, lineptr, count);
			while (token != NULL)
			{
				argv[i] = mystrdup(token);
				if (argv[i] == NULL)
				{
					checkargvelement(argv, linecpy, head, lineptr, count);
				}
				token = strtok(NULL, delim);
				count++;
				i++;
			}
			argv[count] = NULL;
			i = 0;
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
			while ((prompt[i]) != '\0')
			{
				_putchar(prompt[i]);
				i++;
			}
		}
		exitshell(argv, linecpy, head, lineptr, count);
	}
	else if (errno == ENOTTY)
	{
		while (getline(&lineptr, &n, stdin) != -1)
		{
			i = 0;

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
			checkargv(argv, linecpy, head, lineptr, count);
			while (token != NULL)
			{
				argv[i] = mystrdup(token);
				if (argv[i] == NULL)
				{
					checkargvelement(argv, linecpy, head, lineptr, count);
				}
				token = strtok(NULL, delim);
				count++;
				i++;
			}
			argv[count] = NULL;
			i = 0;
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
		exitshell(argv, linecpy, head, lineptr, count);
	}
	else
	{
		perror("isatty");
		exit(1);
	}
	return (0);
}
