#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cmd_mod.h"


char **commands()
{   
    FILE *fd = fopen("/home/ivan/projects/shell/config", "r");
    if(fd == NULL)
    {
        perror("FILE");
    }

    fseek(fd, 0, SEEK_END);
    int size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    char buff_cmds[size];
    buff_cmds[size] = '\0';
    fread(buff_cmds, size/sizeof(char), sizeof(char), fd);
    fclose(fd);

    int max_cmd = 0;
    int numb = 0;
    while(buff_cmds[numb] != 0)
    {
        if(buff_cmds[numb] == '[')
            max_cmd++;
        numb++;
    }

    char **buff = malloc(sizeof(char*) * max_cmd);
    for(size_t i = 0; i < max_cmd; i++)
    {   
        buff[i] = malloc(sizeof(char) * 10);
        memset(buff[i], 0, 10);
    }
    
    int k = 0;
    int index = 0;
        for(size_t j = 0; j < size; j++)
        {
            if(buff_cmds[j] != '[' && buff_cmds[j] != ']')
            {
                buff[index][k] = buff_cmds[j];
                k++;
            }
            else if(buff_cmds[j] == ']')
            {
                buff[index][k + 1] = '\0';
                k = 0;
                index++;
                j++;
            }

        }                                 
    
    return buff;    
}