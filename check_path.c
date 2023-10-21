#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"

int check_path(Simple_cmd **cmd_table, int numb_of_cmds)
{

    for(size_t i = 0; i < numb_of_cmds; i++)
    {   
        if(cmd_table[i]->path == NULL)
        {   
            printf("command \"%s\" is not found\n", cmd_table[i]->command_tokens[0]);
        }

    }
    



    return 1;
}
