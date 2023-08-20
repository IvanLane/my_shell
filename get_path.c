#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "token_struct.h"
#include "simple_command_tokens.h"

char *get_path(char **command_tokens)
{
    char *path = getenv("PATH");
    struct stat buffer;
    int count = 1;
    
    // for(int i = 0; i < strlen(path); i++)
    // {
    //     if(path[i] == ':')
    //         count++;
    // }

    char *real_path = malloc(sizeof(char) * 50);
    memset(real_path, 0, 50);

    int j = 0;
    for(size_t i = 0; i < strlen(path); i++)
    {   
        if(path[i] == ':')
        {   
            strcat(real_path, "/");
            strcat(real_path, command_tokens[0]);
            strcat(real_path, "\0");
                    
            if(stat(real_path, &buffer) == 0)
            {   
                return real_path;
            }
            memset(real_path, 0, 50);
            j = 0;
            i++;
        }

        real_path[j] = path[i];
        j++;
    }
        
    // if(!real_path, &buffer)
    // {   
    //     printf("command \"%s\" is not found \n", command_tokens[0]);
    // }
    // return real_path;

}