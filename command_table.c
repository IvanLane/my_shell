#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "token_struct.h"

Simple_cmd **command_table(char **parser, char *line)
{
    int count = 1;
    int i = 0;
    while(line[i] != 0)
    {   
        if(line[i] == '|')
            count++;
        i++;
    }
    
    Simple_cmd **cmd = malloc(sizeof(Simple_cmd*) * count);
 
    for(int i = 0; i < count; i++)
    {
        cmd[i] = malloc(sizeof(Simple_cmd));
    }

    for(int i = 0; i < count; i++)
    {   
        if(i > 0)
                cmd[i]->_pipe = 1;
        cmd[i]->number_of_commands = count;
        cmd[i]->string = parser[i];
    }

    return cmd;
}