#include <stdlib.h>
#include <string.h>

char *check_symbols(char *line)
{   
    int k = 0;
    
    char *string = malloc(sizeof(char) * 50);
    memset(string, 0, 50);

    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '>')
        {   
            for(int j = i+2; line[j] != '\0'; j++ )
            {
                string[k] = line[j];
                k++;
            }

        }

    }

    return string;
}