#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

char *get_line()
{   
        char *buff = malloc(BUFF_SIZE);
        memset(buff, 0, BUFF_SIZE);
        int i = 0;

        do
        {   
            buff[i] = getchar();
            i++;

        }while(buff[i-1] != '\n');

    return buff;
}