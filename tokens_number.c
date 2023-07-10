#include "string.h"

int tokens_number(char *command_string)
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


    return count;
}