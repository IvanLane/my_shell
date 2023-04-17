#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token_struct.h"

Simple_cmd **parser(char *str, int *number)
{
    char delim = '|';
    char *string = str;
    int count = 1;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == delim)
            count++;
    }
    *number = count;
    
    Simple_cmd **command_table = malloc(sizeof(Simple_cmd*) * count);
    char **str_buff = malloc(sizeof(char*) * count);
    for(int i = 0; i < count; i++)
    {
        command_table[i] = malloc(sizeof(Simple_cmd));
        str_buff[i] = malloc(sizeof(char)*10);
        memset(str_buff[i], 0, 10);
    }

    int j = 0;
    int k = 0;
    int n = 0;

    while(j < strlen(str))
    {   

        if(string[j] != delim)
        {   
            str_buff[k][n] = string[j];
            n++;
        }
        else
        {   
            k++;
            j++;
            n = 0;
            command_table[k]->_pipe = 1;
        }
        j++;
    }
    
    for(int i = 0; i < count; i++)
    {   
        command_table[i]->number_of_commands = count;
        command_table[i]->string = str_buff[i];
    }

    return command_table;
}