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
// #include "exec_command.h"
#include "token_struct.h"


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
        struct command_str **simple = command_table(tokens);
        // simple[0]->tokens



        printf("%s\n", simple[0]->tokens[1]); //print the secons argument of the tokens
        // exec_command(simple);
        
    }


      
    return 0;
}