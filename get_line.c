#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

char *get_line()
{   
        char *buff; 
        buff = malloc(BUFF_SIZE + 1);
        
        memset(buff, 0, BUFF_SIZE + 1);
        int i = 0;
        
        do
        {   
            buff[i] = getchar();
            i++;

            if(i > BUFF_SIZE)
            {   
                (buff = realloc(buff, BUFF_SIZE + 1));
            }

        }while(buff[i - 1] != '\n');

        buff[i - 1] = 0;

    return buff;
}