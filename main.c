#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_line.h"
#include "parser.h"



void mem_free(char *str, char **tokens)
{
    free(str);
    free(tokens);
}


void exec_command(char **tokens)
{   
    getenv("PATH");

    // execve(path, tokens, envp);


}

int main(int argc, char *argv)
{   
    char *prompt = "(my_shell) $:";
    char *exit = "exit"; 

    int r;

    char *str;
    int number_of_tokens;
    char **tokens;

    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, "exit\n"))
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