#include "monty.h"

/**
 * @brief
 *
 * @param str
 */

void trim(char * str)
{
    int index, i;

    index = 0;
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }

    i = 0;
    while(str[i + index] != '\0')
    {
        str[i] = str[i + index];
        i++;
    }
    str[i] = '\0';

    i = 0;
    index = -1;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            index = i;
        }

        i++;
    }

    str[index + 1] = '\0';
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */

int read_file(stack_t **head, char *filename)
{
    FILE *fd;
    char *line_read;
    size_t buffer_size;
    int i;

    (void)head;

    if (head == NULL)
		exit(EXIT_FAILURE);

    fd = fopen(filename, "r");
    if (fd == NULL)
    {
        perror("Error");
        return (1);
    }

    for (i = 1; getline(&line_read, &buffer_size, fd) != -1 ; i++)
    {
        trim(line_read);
        printf("%s", line_read);
    }

    free(line_read);
    fclose(fd);

    return (0);
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char **argv)
{
    stack_t *head;
    stack_t *new;
    stack_t hello = {8, NULL, NULL};
    (void)argv;

    if (argc != 2 )
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    head = &hello;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        dprintf(2, "Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }

    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;

    /* n = print_stack(head);

    printf("-> %d elements\n", n); */

    read_file(&head, argv[1]);
    free(new);
    return (EXIT_SUCCESS);
}

