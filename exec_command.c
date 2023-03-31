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

void exec_command(struct command_str **str_tok)
{   

    char **tokens;

    tokens = str_tok[0]->tokens;

    pid_t pid = fork();
    int status;
    
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
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                    free(real_path);
                }

                free(real_path);
                path_token = strtok(NULL, ":");

                if(path_token == NULL)
                {   
                    printf("command \"%s\" is not found \n", tokens[0]);
                    exit(EXIT_SUCCESS);
                }
            }
    }
}