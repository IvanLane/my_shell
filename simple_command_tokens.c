#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "token_struct.h"
#define MAX 10

char **simple_command_tokens(Simple_cmd **command_table, int pid_numb, char *command_string)
{   
        char delim = ' ';
        int count = 1;
        int z = 0;

     while(command_table[pid_numb]->string[z] != '\0')
        {
            if(command_table[pid_numb]->string[z] == delim)
            {
                count++;
            }
            z++;
        }

        char command[count][MAX];

        int x = 0;
        int k = 0;
        int j = 0;

        char **simple_command = malloc(sizeof(char*) * count);

        while(1)
        {   
            if(command_table[pid_numb]->string[x] == delim)
            {   
                command[k][j] = 0;
                simple_command[k] = strdup(command[k]);
                j = 0;
                k++;
                x++;
            }
            else if(command_table[pid_numb]->string[x] == '\0')
            {
                command[k][j] = 0;
                simple_command[k] = strdup(command[k]);
                simple_command[k + 1] = NULL;
                break;
            }

            command[k][j] = command_table[pid_numb]->string[x];
            j++;
            x++;
        }

    return simple_command;
}
