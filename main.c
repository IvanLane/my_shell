#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "get_line.h"
#include "parser.h"
#include "exec_command.h"


void mem_free(char *str, char **tokens)
{
    free(str);
    free(tokens);
}

int main(int argc, char *argv)
{   
    char *prompt = "my_shell_$: ";
    char *exit = "exit"; 
    char *str;
    int number_of_tokens;
    char **tokens;

    // char **tokens1 = malloc(sizeof(char*)*2);
    // tokens1[0] = "ls";
    // tokens1[1] = "-al";

    // char **tokens2 = malloc(sizeof(char*)*2);
    // tokens2[0] = "grep"; 
    // tokens2[1] = "a.out";

    // pipe_func(tokens1, tokens2);
    
    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, exit))
        {
            mem_free(str, tokens);
            printf("your shell is closed\n");
            return -1;
        }

        tokens = parser(str, &number_of_tokens);
        exec_command(tokens);
        
    }


      
    return 0;
}