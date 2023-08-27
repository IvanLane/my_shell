#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void touch_cmd(char **tokens)
{       
    struct stat buff;
    if(stat(tokens[1], &buff) == -1)
    {
        int file_d = open(tokens[1], O_RDWR | O_CREAT, 0777);
        close(file_d);
    }
    else 
        printf("file exists\n");


}