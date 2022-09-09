#include "monty.h"


/**
 * pop_top - Adds a node to the stack.
 *
 * @node: Pointer to a pointer pointing to node the top node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (node == NULL || *node == NULL)

	tmp = *node;
	*node = tmp->next;
	if (*node != NULL)
		(*node)->prev = NULL;
	free(tmp);
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 *
 * @node: Pointer to a pointer pointing to node the top node.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **node, unsigned int line_number)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)

	tmp = (*node)->next;
	(*node)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *node;
	tmp->next = *node;
	(*node)->prev = tmp;
	tmp->prev = NULL;
	*node = tmp;
}


