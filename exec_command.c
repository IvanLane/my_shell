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

void exec_command(Simple_cmd **command_table)
{   
    pid_t pid = fork();
    int status;
    int count = command_table[0]->number_of_commands;

    if(pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    else if(pid == 0)
    {   
        char **malloc_command = simple_command_tokens(command_table, command_table[0]->string); 
        for(int i = 0; i < command_table[0]->number_of_commands; i++)
        {
            char *path = getenv("PATH");
            char *command_path = strtok(path, ":");
            int command_length = strlen(malloc_command[0]);
            struct stat buffer;

                while(command_path != NULL)
                {
                    char *real_path = malloc(command_length + strlen(command_path) + 2);
            
                    strcpy(real_path, command_path);
                    strcat(real_path, "/");
                    strcat(real_path, malloc_command[0]);
                    strcat(real_path, "\0");

                    if(stat(real_path, &buffer) == 0)
                    {   
                        if(execve(real_path, malloc_command, NULL) == -1)
                        {
                            perror("execve");
                            exit(EXIT_FAILURE);
                        }
                    }

                    free(real_path);
                    command_path = strtok(NULL, ":");

                    if(command_path == NULL)
                    {   
                        printf("command \"%s\" is not found \n", malloc_command[0]);
                        exit(EXIT_SUCCESS);
                    }
                }
        }
    }
    else if(pid != 0)
    {
    // for(int i = 0 i < malloc_command)
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if(WIFSIGNALED(status))
        {
            printf("killed by signal: %d\n", WTERMSIG(status));
        }
        else if(WIFSTOPPED(status))
        {
            printf("stopped by signal: %d\n", WSTOPSIG(status));
        }
        else if(WIFCONTINUED(status))
        {
            printf("continued");
        }
    }
        
}