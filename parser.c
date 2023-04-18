#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parser(char *str)
{
    char delim = '|';
    char *string = str;
    int count = 1;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == delim)
            count++;
    }
    
    char **str_buff = malloc(sizeof(char*) * count);
    for(int i = 0; i < count; i++)
    {
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
            str_buff[k][n - 1] = 0;
            k++;
            j++;
            n = 0;
        }
        j++;
    }

    return str_buff;
}