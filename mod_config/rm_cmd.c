#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void rm_cmd(char **tokens)
{   
    struct stat buff;
        if(stat(tokens[1], &buff) == 0)
            remove(tokens[1]);
        else
            printf("file is not exist\n");
    
}