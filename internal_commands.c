#include <string.h>
#include "stdio.h"
#include "unistd.h"
#include "sys/stat.h"
#include "sys/types.h"

void internal_commands(char **tokens)
{   
    struct stat buff;

    if(!strcmp(tokens[0], "cd"))
    {
        char dir[20];   
        int cd = chdir(tokens[1]);
        getcwd(dir, 20);
    }
    else if(!strcmp(tokens[0], "newdir"))
    {       
        if(stat(tokens[1], &buff) == -1)
        {
            mkdir(tokens[1], 0777);
        }
        else
            printf("directory exists\n");
    }
}