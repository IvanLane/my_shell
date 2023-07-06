#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#include "simple_command_tokens.h"
#include "get_path.h"

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

    
    Simple_cmd **cmd_table = malloc(sizeof(Simple_cmd*) * count);
 
    for(int i = 0; i < count; i++)
    {   
        cmd_table[i] = malloc(sizeof(Simple_cmd));
        cmd_table[i]->string = parser[i];
        cmd_table[i]->pnt_token_func = simple_command_tokens;
        cmd_table[i]->command_tokens = cmd_table[i]->pnt_token_func(cmd_table[i]->string);
        cmd_table[i]->pnt_get_path = get_path;
        cmd_table[i]->path = cmd_table[i]->pnt_get_path(cmd_table[i]->command_tokens);
    }

    return cmd_table;
}