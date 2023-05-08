#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "get_line.h"
#include "token_struct.h"
#include "parser.h"
#include "simple_command_tokens.h"



int main(int argc, char *argv)
{   
    char *prompt = "my_shell_$: ";
    char *exit = "exit"; 
    char *str;
    int number_of_tokens;
    char **parse_commands;
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

        parse_commands = parser(str);
        char **cmd_tokens = simple_command_tokens(parse_commands[0]);
        table = command_table(parse_commands, str);
       
        printf("%s\n", table[0]->command_tokens[0]);
        printf("%s\n", table[0]->command_tokens[1]);
        printf("%s\n", table[1]->command_tokens[0]);
     }


      
    return 0;
}