#include <stdio.h>

int number_of_commands(char *line)
{
    int count = 1;
    int i = 0;
    while(line[i] != 0)
    {   
        if(line[i] == '|')
            count++;
        i++;
    }

    return count;
}