#include "monty.h"

/**
 * mod_top - Finds the modulus of the top two elements of the stack.
 * @node: Pointer to the top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_top(stack_t **node, unsigned int line_number)
{
	int mod;

	if (node == NULL || *stack == NULL || (*node)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}


	if ((*node)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	mod = (*node)->n % (*node)->prev->n;
	(*node)->n = mod;
	free((*node)->prev);
	(*node)->prev = NULL;
}
