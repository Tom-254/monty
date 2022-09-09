#include "monty.h"

/**
 * @brief
 *
 * @param str
 */

void pass_string(char *str, unsigned int line_number )
{
    char *token;
    char *opcode;
    char *value;

    token = strtok(str, "\n \t\r");
    opcode = token;
    token = strtok(NULL, "\n \t\r");
    value = token ? token : "error";


    find_function(opcode, value, line_number);
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */

int read_file(char *filename)
{
    FILE *fd;
    char *line_read;
    size_t buffer_size;
    unsigned int line_num;

    fd = fopen(filename, "r");
    if (fd == NULL)
    {
        perror("Error");
        return (1);
    }
    printf("hello");
    for (line_num = 1; getline(&line_read, &buffer_size, fd) != -1 ; line_num++)
    {
        printf("hello");
        pass_string(line_read, line_num);
        /* printf("%s\n", line_read); */
    }

    printf("hello");

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
int main(int argc, char **argv, char **environ)
{
    (void)environ;
    if (argc != 2 )
    {
        dprintf(STDERR_FILENO, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    printf("hello");
    read_file(argv[1]);
    return (EXIT_SUCCESS);
}

