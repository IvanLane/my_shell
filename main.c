#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "get_line.h"
#include "exec_command.h"
#include "token_struct.h"


// void mem_free(char *str, char **tokens, Simple_cmd **simple)
// {
//     free(str);
//     free(tokens);
//     free(simple);
// }

int main(int argc, char *argv)
{   
    char *prompt = "my_shell_$: ";
    char *exit = "exit"; 
    char *str;
    int number_of_tokens;
    char **tokens;
    Simple_cmd **table;

    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, exit))
        {
            printf("your shell is closed\n");
            return -1;
        }

        table = parser(str, &number_of_tokens);
        // printf("%s \n", table[0]->string);
        // printf("%d \n", table[1]->_pipe);
        // printf("%s \n", table[1]->string);
        // printf("%s \n", table[2]->string);
        // simple = command_table(tokens);
        exec_command(table);        
    }


      
    return 0;
}