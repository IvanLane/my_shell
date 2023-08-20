#include <stdio.h>
#include <sys/stat.h>
#include <string.h> 
#include "cmd_mod.h"

void mkdir_cmd(char **tokens)
{   
        struct stat buff;
        if(stat(tokens[1], &buff) == -1)
        {
            mkdir(tokens[1], 0777); 
        }
        else
            printf("directory exists\n");
}

