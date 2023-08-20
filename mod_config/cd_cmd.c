#include <stdio.h>
#include <string.h> 
#include <unistd.h>

#include "cmd_mod.h"

void cd_cmd(char **tokens)
{
    if(!strcmp(tokens[0], "cd"))
    {
        char dir[20];   
        int cd = chdir(tokens[1]);
        getcwd(dir, 20);
    }
}