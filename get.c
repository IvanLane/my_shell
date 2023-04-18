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

char *get_path(char **command_tokens, int count)
{
            char *path = getenv("PATH");
            char *command_path = strtok(path, ":");
            int command_length = strlen(command_tokens[0]);
            struct stat buffer;

                while(command_path != NULL)
                {
                    char *real_path = malloc(command_length + strlen(command_path) + 2);

                    strcpy(real_path, command_path);
                    strcat(real_path, "/");
                    strcat(real_path, command_tokens[0]);
                    strcat(real_path, "\0");

                    if(stat(real_path, &buffer) == 0)
                    {   
                        // if(execve(real_path, command_tokens, NULL) == -1)
                        // {
                        //     perror("execve");
                        //     exit(EXIT_FAILURE);
                        // }
                        return real_path;
                    }

                    free(real_path);
                    command_path = strtok(NULL, ":");

                    if(command_path == NULL)
                    {   
                        printf("command \"%s\" is not found \n", command_tokens[0]);
                        exit(EXIT_SUCCESS);
                    }
                }

}