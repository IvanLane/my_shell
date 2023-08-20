#include <stdio.h>
#include <sys/stat.h>
#include <string.h> 
#include "cmd_mod.h"

void rmdir_cmd(char **tokens)    
{
        struct stat buff;
        if(stat(tokens[1], &buff) == 0)
        {   
            rmdir(tokens[1]);
        }
        else
            printf("directory is not exist\n");
}