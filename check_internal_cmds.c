#include "string.h"

int check_internal_cmds(char *internal_cmds[], char **tokens)
{   
    for(int i = 0; i < 7; i++)
    {
        if(!strcmp(tokens[0], internal_cmds[i]))
        {
            return 1;
        }
    }

    return 0;
}