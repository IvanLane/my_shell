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
#include "get_path.h"

void exec_command(Simple_cmd **command_table)
{   
    int count = command_table[0]->number_of_commands;
    int status;
    
    int fd_index = count - 1;

    char **path = malloc(sizeof(char*) * count);
    for(int i = 0; i < count; i++)
    {
        path[i] = malloc(sizeof(char) * 100);
        memset(path[i], 0, 100);
    }
    
    int fd[fd_index][2];
    pid_t pids[count];

    for (int i = 0; i < count; i++)
    {
        if (pipe(fd[i]) == -1)
            perror("pipe");
        }
    char **command_tokens;
        

        for(int pid_numb = 0; pid_numb < count; pid_numb++ )
        {
            if(pid_numb == 0)
            {
                pids[pid_numb] = fork();
                if(pids[pid_numb] == -1)
                 {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }

                if(pids[pid_numb] == 0)
                {
                    if(count == 1)
                    {
                        close(fd[pid_numb][0]);
                        close(fd[pid_numb][1]);
                        char **command_tokens = simple_command_tokens(command_table, pid_numb, command_table[pid_numb]->string);
                        path[pid_numb] = get_path(command_tokens);
                        if(execve(path[pid_numb], command_tokens, NULL) == -1)
                        {
                            perror("execve");
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {   
                        dup2(fd[pid_numb][1], STDOUT_FILENO);
                        for(int j = 0; j < fd_index; j++)
                        {
                            close(fd[j][0]);
                            close(fd[j][1]);
                        }
                        command_tokens = simple_command_tokens(command_table, pid_numb, command_table[pid_numb]->string); 
                        path[pid_numb] = get_path(command_tokens);
                        if(execve(path[pid_numb], command_tokens, NULL) == -1)
                        {
                            perror("execve");
                            exit(EXIT_FAILURE);
                        }
                    }
                }           
            }
            else if(pid_numb == count - 1)
            {
                pids[pid_numb] = fork();
                if(pids[pid_numb] == 0)
                {   
                    dup2(fd[pid_numb - 1][0], STDIN_FILENO);
                    for(int j = 0; j < fd_index; j++)
                    {
                        close(fd[j][0]);
                        close(fd[j][1]);
                    }
                    command_tokens = simple_command_tokens(command_table, pid_numb, command_table[pid_numb]->string); 
                    path[pid_numb] = get_path(command_tokens);
                    if(execve(path[pid_numb], command_tokens, NULL) == -1)
                    {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                }         
            }
            else
            {
                pids[pid_numb] = fork();
                if(pids[pid_numb] == 0)
                {   
                    dup2(fd[pid_numb - 1][0], STDIN_FILENO);
                    dup2(fd[pid_numb][1], STDOUT_FILENO);
                    for(int j = 0; j < fd_index; j++)
                    {
                        close(fd[j][0]);
                        close(fd[j][1]);
                    }
                    command_tokens = simple_command_tokens(command_table, pid_numb, command_table[pid_numb]->string); 
                    path[pid_numb] = get_path(command_tokens);
                    if(execve(path[pid_numb], command_tokens, NULL) == -1)
                    {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                } 
            }
        }

        for(int i = 0; i < fd_index; i++)
        {
            close(fd[i][0]);
            close(fd[i][1]);
        }

        for(int i = 0; i < count; i++)
        {
            free(path[i]);
        }
        free(path);

        for(int i = 0; i < count; i++)
        {
            waitpid(pids[i], &status, WUNTRACED | WCONTINUED);
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