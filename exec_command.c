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
#include "execution.h"

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
        execution(malloc_command, count);
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