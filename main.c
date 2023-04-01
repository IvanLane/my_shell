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
#include "token_struct.h"


void mem_free(char *str, char **tokens, Simple_cmd **simple)
{
    free(str);
    free(tokens);
    free(simple);
}

int main(int argc, char *argv)
{   
    char *prompt = "my_shell_$: ";
    char *exit = "exit"; 
    char *str;
    int number_of_tokens;
    char **tokens;
    Simple_cmd **simple;

    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, exit))
        {
            mem_free(str, tokens, simple);
            printf("your shell is closed\n");
            return -1;
        }

        tokens = parser(str, &number_of_tokens);
        simple = command_table(tokens);
        exec_command(simple);        
    }


      
    return 0;
}