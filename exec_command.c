#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#include "token_struct.h"
#include "simple_command_tokens.h"
#include "get_path.h"
#include "number_of_command.h"
#include "infile.h"

void exec_command(Simple_cmd **command_table, int number_of_cmd, char *infile, char *append_infile)
{   
    int count = number_of_cmd;
    int status;
    
    int fd_index = count - 1;
    
    int fd[fd_index][2];
    pid_t pids[count];

    if(count > 1)
    {
        for (int i = 0; i < count; i++)
        {
            if (pipe(fd[i]) == -1)
                perror("pipe");
            }
    }

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
                signal(SIGINT, SIG_DFL);
                signal(SIGTSTP, SIG_DFL);

                if(count == 1)
                {
                    if(infile != NULL)
                    {
                        int file_d = open(infile, O_RDWR | O_CREAT, 0777);
                        dup2(file_d, STDOUT_FILENO);
                        close(file_d);
                        if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                        {   
                            perror("error");
                            exit(EXIT_FAILURE);
                        }
                    }
                    else if(append_infile != NULL)
                    {
                        int file_d = open(append_infile, O_RDWR | O_APPEND, 0777);
                        dup2(file_d, STDOUT_FILENO);
                        close(file_d);
                        if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                        {
                            perror("error");
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {   
                        if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                        {   
                            perror("error");
                            exit(EXIT_FAILURE);
                        }

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
                    if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                    {
                        perror("error");
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

                if(infile > 0)
                {
                    int file_d = open(infile, O_RDWR | O_CREAT, 0777);
                    dup2(file_d, STDOUT_FILENO);
                    close(file_d);
                    close(fd[pid_numb][0]);
                    close(fd[pid_numb][1]);
                    if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                        {
                            perror("error");
                            exit(EXIT_FAILURE);
                        }
                }
                else if(append_infile > 0)
                {
                    int file_d = open(append_infile, O_RDWR | O_APPEND, 0777);
                    dup2(file_d, STDOUT_FILENO);
                    close(file_d);
                    close(fd[pid_numb][0]);
                    close(fd[pid_numb][1]);
                    if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                        {
                            perror("error");
                            exit(EXIT_FAILURE);
                        }
                }    
                else
                {
                    if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                    {
                        perror("error");
                        exit(EXIT_FAILURE);

                    }
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
                if(execve(command_table[pid_numb]->path, command_table[pid_numb]->command_tokens, NULL) == -1)
                {
                    perror("error");
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
        // do{
        if(waitpid(pids[i], &status, WUNTRACED | WCONTINUED) == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) 
        {
            printf("process exited with status: %d\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))
        {
            printf("process killed by signal: %d\n", WTERMSIG(status));
        }
        else if(WIFSTOPPED(status))
        {
           printf("process stopped by signal: %d\n", WSTOPSIG(status));
        }
        else if(WIFCONTINUED(status))
        {
            printf("CONTINUED\n");
        }
        // } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

}