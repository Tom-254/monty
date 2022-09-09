#include "monty.h"


/* stack_t *create_node(int value)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    new->n = value;
    new->next = NULL;
    new->prev = NULL;
    return (new);
} */

void find_function(char *opcode, char *value, unsigned int line_number)
{
    int i;
    int converted_value;
    /* stack_t *node; */
    instruction_t funct_list[] = {
        {"push", push_stack},
        {NULL, NULL}
    };

    (void)line_number;
    (void)converted_value;
    if (!strcmp(value, "error") == 0)
    {
        converted_value = atoi(value);
        for (i = 0; funct_list[i].opcode;  i++)
        {
            if (strcmp(funct_list[i].opcode, opcode) == 0)
            {
                printf("hello");
                /* funct_list[i].f(&node, line_number); */
                /* free(node); */
                break;
            }
        }
    }
    else
        for (i = 0; funct_list[i].opcode;  i++)
        {
            if (strcmp(funct_list[i].opcode, opcode) == 0)
                printf("%s\n", opcode);
        }
}

