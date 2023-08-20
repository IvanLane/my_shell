#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_stat(char *line)
{
    if(!strcmp(line, "exit"))
    {
        printf("shell is closed\n");
        free(line);
        exit(EXIT_SUCCESS);
    }
}