#include <stdlib.h>
#include <string.h>

char *infile(char *line)
{   
    int k = 0;
    
    if(strchr(line, '>') && !strstr(line, ">>"))
    {
        char *string = malloc(sizeof(char) * 50);
        memset(string, 0, 50);

        for(int i = 0; i < strlen(line); i++)
        {
            if(line[i] == '>' && line[i + 1] != '>' && line[i - 1] != '>')
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
    else
        return 0;

}