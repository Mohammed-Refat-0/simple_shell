#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * free_list -  function that frees list_t list.
 * @head: a pointerto the head of list
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *ptr;

	if (!head)
	{
		return;
	}
	while (head != NULL)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}

}
/**
 *create_path_list - create a linked list of path evirnoment
 *Return: head pointer of created linked list, otherwise null
 */
list_t *create_path_list(void)
{
	char *pathptr;
	char *pathptrcpy;
	char *token;
	list_t *head = NULL;

	pathptr = mygetenv("PATH");
	if (pathptr == NULL)
	{
		return (NULL);
	}
	pathptrcpy = mystrdup(pathptr);
	if (!pathptrcpy)
	{
		return (NULL);
	}
	token = strtok(pathptrcpy, ":");
	while (token)
	{
		list_t *newnode = malloc(sizeof(list_t));

		if (!newnode)
		{
			free(pathptrcpy);
			free_list(head);
			return (NULL);
		}
		newnode->len = mystrlen(token);
		newnode->str = mystrdup(token);
		if (!newnode->str)
		{
			free(pathptrcpy);
			free_list(head);
			return (NULL);
		}
		newnode->next = head;
		head = newnode;
		token = strtok(NULL, ":");
	}
	free(pathptrcpy);
	return (head);
}
/**
 *myexit - exit the shell
 *@n: value to exit with
 * Return: void
 */
void myexit(int n)
{
	exit(n);
}
/**
 *myenv - prints the cureent working envirnoment
 *@environ: pointer to head pointer of current envirnoment varaiable
 *Return: 0
 */
int myenv(char **environ)
{
	int i = 0;
	int j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
	return (0);
}
