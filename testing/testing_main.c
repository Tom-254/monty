#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    FILE             *fd;
    size_t          len;
    size_t          buffer_size;
    char            *line;
    unsigned int    i;

    line         = NULL;
    buffer_size  = 0;

    if( argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    fd = fopen(argv[1], "r");
    if(fd == NULL)
    {
        dprintf(STDERR_FILENO, "Could not open %s\n", argv[1]);
        perror("Error: ");
        return 1;
    }



    for(i=1; -1  != (len = getline(&line, &buffer_size, fd ));i++ )
        printf("%4u: %4lu %s", i, len, line);

    free(line);
    fclose(fd);

    return 0;

}
