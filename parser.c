#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

char **parser(char *line, int number_of_cmd)
{
    char delim_pipe = '|';

    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '>' && line[i + 1] != '>')
        {    
            line[i-1] = '\0';
        }
        else if(line[i] == '>' && line[i + 1] == '>')
        {
            line[i-1] = '\0';
        }
    }

    int count = number_of_cmd;
    
    char **parse_commands = (char**) malloc(sizeof(char*) * count);
    
    for(int i = 0; i < count; i++)
    {
        parse_commands[i] = malloc(sizeof(char)*MAX);
        memset(parse_commands[i], 0, MAX);
    }

    int index = 0;
    int k = 0;
    int j = 0;

    while(index < strlen(line))
    {   
        if(line[index] != delim_pipe)
        {   
            parse_commands[k][j] = line[index];
            j++;
        }
        else
        {   
            parse_commands[k][j - 1] = '\0';
            k++;
            index++;
            j = 0;
        }
        index++;
    }

    return parse_commands;
}