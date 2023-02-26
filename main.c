#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_line.h"

char **parser(char *str)
{   
    int n = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
            n++;
    }
    char **buffer = malloc(sizeof(char*) * n);
    
    char *delim = " ";
    char *token;
    token = strtok(str, delim);

    int i = 0;
    while(token != NULL)
    {
        buffer[i] = malloc(sizeof(char)*10);
        memset(buffer[i], 0, 10);
        buffer[i] = token;
        token = strtok(NULL, delim);
        // printf("%s \n", buffer[i]);
        i++;
    }
    buffer[i] = NULL;

    return buffer;
}

int main(int argc, char *argv)
{   
    char *prompt = "(my_shell) $:";
    char *exit = "exit"; 

    char *str;
    char **tokens;

    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, "exit\n"))
        {
            printf("your shell is closed\n");
            free(str);
            return -1;
        }

        tokens = parser(str);
    }


    puts(str);
    
   
    return 0;
}