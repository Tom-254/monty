#include "monty.h"


void nop(stack_t **node, unsigned int line_number)
{
    (void)node;
    (void)line_number;
    return;
}

void print_top(stack_t **node, unsigned int line_number)
{
    (void)node;
    (void)line_number;
    /* dprintf(STDOUT_FILENO, "%d",(*node)->n); */

}

void push_stack(stack_t **node, unsigned int line_number)
{
    (void)node;
    (void)line_number;
    printf("inside");
    /* add_dnodeint(); */
}

