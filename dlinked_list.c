#include "monty.h"

/**
 * print_stack - print a doubly linked lists content
 *
 *
 * @h: pointer to the head of the list to print
 * Return: the number of nodes
 */

size_t print_stack(const stack_t *h)
{
	size_t n_total;

	for (n_total = 0; h != NULL; n_total++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

	return (n_total);
}

/**
 * stack_len - returns the number of elements in a linked stack_t list.
 * @h: struct linked list
 * Return:  number of elements in a linked
 */

size_t stack_len(const stack_t *h)
{
	int node_count = 0;

	while (h != NULL)
	{
		h = h->next;
		node_count++;
	}

	return (node_count);
}

/**
 * add_dnodeint - adds a new node at the
 * beginning of a stack_t list.
 *
 * @head: pointer to pointer to the head of the list
 * @n: value to add to the head
 * Return: the address of the new element,
 * or NULL if it failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	*head = new;
	if (new->next != NULL)
		(new->next)->prev = new;

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 *
 * @head: pointer to pointer to the head of the list
 * @n: value to add to the head
 * Return: the address of the new element,
 * or NULL if it failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (current->next)
			current = current->next;

		new->prev = current;
		current->next = new;
	}
	return (new);
}

/**
 * free_dlistint - function that frees a dlistint_t list.
 *
 * @head: pointer to pointer to the head of the list
 * Return: nothing
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}


