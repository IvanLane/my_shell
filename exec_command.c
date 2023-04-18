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
    // pid_t pid = fork();
    
    
    int status;
    int count = command_table[0]->number_of_commands;
    int fd[count][2];

    if(count == 1)
    {   
        pid_t pid = fork();
        if(pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        else if(pid == 0)
        {   
            close(fd[count][0]);
            close(fd[count][1]);
            char **command_tokens = simple_command_tokens(command_table, command_table[0]->string); 
            char *path = get_path(command_tokens);
            if(execve(path, command_tokens, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else if(pid != 0)
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
            close(fd[count][0]);
            close(fd[count][1]);
        }
    }
    // else if(count > 1)
    // {
    //     pid_t pids[count + 1];
    // // // int fd[count][2];

    //     for(int i = 0; i < count; i++)
    //     {
    //         if(pipe(fd[i]) == -1)
    //             perror("pipe");
    //     }
    //     int close_fd = 0;

    //     for(int pid_numb = 0; pid_numb < count + 1; pid_numb++ )
    //     {
    //         if(pid_numb == 0)
    //         {
    //             pids[pid_numb] = fork();
    //             if(pids[pid_numb] == 0)
    //             {
    //                 dup2(fd[pid_numb][1], STDOUT_FILENO);
    //                 for(int j = 0; j < count; j++)
    //                 {
    //                     close(fd[j][0]);
    //                     close(fd[j][1]);
    //                 }
    //                 char **command_tokens = simple_command_tokens(command_table, command_table[0]->string); 
    //                 execution(command_tokens, count);
    //             }           
    //         }
    //         else if(pid_numb = count)
    //         {
    //             pids[pid_numb] = fork();
    //             if(pids[pid_numb] == 0)
    //             {
    //                 dup2(fd[pid_numb][0], STDIN_FILENO);
    //                 for(int j = 0; j < count; j++)
    //                 {
    //                     close(fd[j][0]);
    //                     close(fd[j][1]);
    //                 }
    //                 char **command_tokens = simple_command_tokens(command_table, command_table[0]->string); 
    //                 execution(command_tokens, count);
    //             }         
    //         }
    //         else
    //         {
    //             pids[pid_numb] = fork();
    //             if(pids[pid_numb] == 0)
    //             {   
    //                 dup2(fd[pid_numb][0], STDIN_FILENO);
    //                 dup2(fd[pid_numb][1], STDOUT_FILENO);
    //                 for(int j = 0; j < count; j++)
    //                 {
    //                     close(fd[j][0]);
    //                     close(fd[j][1]);
    //                 }
    //                 char **command_tokens = simple_command_tokens(command_table, command_table[0]->string); 
    //                 execution(command_tokens, count);
    //             } 
    //         }
    //     }

    //     for(int i = 0; i < count; i++)
    //     {
    //         close(fd[i][0]);
    //         close(fd[i][1]);
    //     }
    //     for(int i = 0; i < count; i++)
    //     {
    //         waitpid(pids[i], NULL, 0);
    //     }
    // }

    
        
}