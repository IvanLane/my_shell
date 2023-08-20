#include <stdio.h>
#include <string.h> 
#include <unistd.h>
#include <sys/stat.h>

#include "cmd_mod.h"

void cd_cmd(char **tokens)
{   
        struct stat buff;
        if(stat(tokens[1], &buff) == -1)
        {
            printf("directory is not exist\n");
        }
        else
        {
            char dir[20];   
            int cd = chdir(tokens[1]);
            getcwd(dir, 20);
        }
}