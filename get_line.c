#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

char *get_line()
{   
        char *buff; 
        if(!(buff = malloc(BUFF_SIZE)))
        {
            perror("ERROR");
        }
        
        memset(buff, 0, BUFF_SIZE);
        int i = 0;
        
        do
        {   
            buff[i] = getchar();
            i++;

            if(i > BUFF_SIZE)
            {   
                if(!(buff = realloc(buff, BUFF_SIZE)))
                {
                    perror("ERROR");
                }
            }

        }while(buff[i-1] != '\n');

        buff[i - 1] = 0;

    return buff;
}