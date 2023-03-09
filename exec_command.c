#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


void exec_command(char **tokens)
{   
    pid_t pid = fork();

    if(pid != 0)
    {
        wait(NULL);
    }
    else if(pid == 0)
    {    
        char *path = getenv("PATH");

        char *path_token = strtok(path, ":");
        int command_length = strlen(tokens[0]);
        struct stat buffer;

            while(path_token != NULL)
            {
                char *real_path = malloc(command_length + strlen(path_token) + 2);
        
                strcpy(real_path, path_token);
                strcat(real_path, "/");
                strcat(real_path, tokens[0]);
                strcat(real_path, "\0");

                if(stat(real_path, &buffer) == 0)
                {   
                    if(execve(real_path, tokens, NULL) == -1)
                    {
                        perror("ERROR:");
                    }
                    free(real_path);
                }

                free(real_path);
                path_token = strtok(NULL, ":");

                if(path_token == NULL)
                {   
                    printf("command \"%s\" is not found \n", tokens[0]);
                    exit(1);
                }
            }
    }
}