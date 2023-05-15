#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#define MAX 50

char **simple_command_tokens(char *command_string)
{   
        char delim = ' ';
        int count = 1;
        int numb = 0;

        while(numb < strlen(command_string))
        {
            if(command_string[numb] == delim)
                count++;
            numb++;
        }
        
        int token_number = 0;
        int index = 0;

        char **simple_command = malloc(sizeof(char*) * count);
        for(int i = 0; i < count; i++)
        {
            simple_command[i] = malloc(sizeof(char) * 10);
            memset(simple_command[i], 0, 10);
        }

        for(int i = 0; command_string[i] != '\0'; i++)
        {
            if(command_string[i] == delim)
            {
                token_number++;
                index = 0;
                i++;
            }

            simple_command[token_number][index] = command_string[i];
            index++;
        }

    return simple_command;
}
