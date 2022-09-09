#include "monty.h"

/**
 * create_node - creates nodes for doubly linked lists
 *
 * @value: Interger representing the number to be added to list
 * Return: new node
 */

stack_t *create_node(int value)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * check_if_int - check to see if value passed is integer
 *
 * @value: char representing the number to be added to list
 * @num: Integer repsenting num to add to list
 * Return: integer
 */

int check_if_int(char *value, int num)
{
	if (!strcmp(value, "0") == 0 && num == 0)
		return (1);
	return (0);
}

/**
 * print_push_error - returns error on push
 *
 * @line_number: Interger representing the line number of of the opcode.
 *
 */
void print_push_error(int line_number)
{
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * find_function - finds the correct function to execute opcode
 *
 * @opcode: the instruction code
 * @value: value to add to linked list
 * @line_number: Interger representing the line number of of the opcode.
 *
 */
void find_function(char *opcode, char *value, unsigned int line_number)
{
	int i;
	int converted_value;
	stack_t *node;
	instruction_t funct_list[] = {
		{"push", push_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"nop", nop},
		{"pop", pop_top},
		{"swap", swap_nodes},
		{"add", add_top},
		{NULL, NULL}
	};

	if (!strcmp(value, "error") == 0)
	{
		converted_value = atoi(value);
		node = create_node(converted_value);
		for (i = 0; funct_list[i].opcode;  i++)
			if (strcmp(funct_list[i].opcode, opcode) == 0)
			{
				funct_list[i].f(&node, line_number);
				return;
			}
	}
	else
		for (i = 0; funct_list[i].opcode;  i++)
			if (strcmp(funct_list[i].opcode, opcode) == 0)
			{
				funct_list[i].f(&head, line_number);
				return;
			}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

