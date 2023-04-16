#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "token_struct.h"
#include "exec_command.h"

#define MAX 10

void exec_command(Simple_cmd **command_table)
{   
    pid_t pid = fork();
    int status;
    // printf("hi");
    
    if(pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(pid != 0)
    {
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
    else if(pid == 0)
    {    
        char *path = getenv("PATH");

        char delim = ' ';
        int count = 1;
        int z = 0;

        while(command_table[0]->string[z] != '\0')
        {
            if(command_table[0]->string[z] == delim)
            {
                count++;
            }
            z++;
        }

        char command[count][MAX];

        int x = 0;
        int k = 0;
        int j = 0;

        char **malloc_command = malloc(sizeof(char*) * count);
        
        while(1)
        {   
            if(command_table[0]->string[x] == delim)
            {   
                command[k][j] = 0;
                malloc_command[k] = malloc(sizeof(char) * MAX);
                malloc_command[k] = command[k];
                j = 0;
                k++;
                x++;
            }
            else if(command_table[0]->string[x] == '\0')
            {
                command[k][j] = 0;
                malloc_command[k] = malloc(sizeof(char) * MAX);
                malloc_command[k + 1] = malloc(sizeof(char));
                malloc_command[k] = command[k];
                malloc_command[k + 1] = NULL;
                break;
            }

            command[k][j] = command_table[0]->string[x];
            j++;
            x++;
        }

        char *command_path = strtok(path, ":");
        int command_length = strlen(command[0]);
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
                    printf("%s \n", real_path);  
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
                    printf("command \"%s\" is not found \n", command[0]);
                    exit(EXIT_SUCCESS);
                }
            }
    }
}