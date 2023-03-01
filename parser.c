#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parser(char *str, int *number)
{   
    int num = 1;
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == ' ')
            num++;
    }
    *number = num;
    // printf("%d \n", *number);
    char **buffer = malloc(sizeof(char*)*num);
    
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