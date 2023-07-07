#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *append_infile(char *line)
{
    int k = 0;
    
    if(strstr(line, ">>"))
    {
        char *string = malloc(sizeof(char) * 20);
        memset(string, 0, 20);

        for(int i = 0; i < strlen(line); i++)
        {
            if(line[i] == '>' && line[i + 1] == '>')
            {   
                for(int j = i+3; line[j] != '\0'; j++ )
                {
                    string[k] = line[j];
                    k++;
                }
                string[k] = '\0';
            }
        }

        return string;
    }
    else
        return 0;
}