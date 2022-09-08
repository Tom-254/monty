#include "monty.h"

void find_function(char *opcode, char )
{
    instruction_t funct_list[] = {
        {"push", push_stack},
        {"pall", print_stack},
        {"pint", print_top},
        {"pop", pop_top},
        {"nop", nop},
        {NULL, NULL}
    }
}

