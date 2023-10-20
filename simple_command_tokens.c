#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#define MAX 1024

char **simple_command_tokens(char *line)
{   
        char delim = ' ';
        int count = 1;
        int numb = 0;

        while(numb <=strlen(line))
        {
            if(line[numb] == delim)
                count++;
            numb++;
        }
        
        int token_number = 0;
        int index = 0;

        char **simple_command = malloc(sizeof(char*) * (count + 1));
        simple_command[count] = NULL;

        for(size_t i = 0; i < count; i++)
        {   
            simple_command[i] = calloc(MAX, sizeof(char));
        }

        for(size_t i = 0; i < numb; i++)
        {
            if(line[i] == delim)
            {   
                token_number++;
                index = 0;
                i++;
            }

            simple_command[token_number][index] = line[i];
            index++;
        }
    

    return simple_command;
}
