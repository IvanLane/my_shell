#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "get_line.h"
#include "number_of_command.h"
#include "parser.h"
#include "simple_command_tokens.h"
#include "token_struct.h"
#include "exec_command.h"
#include "memory_free.h"


int main(int argc, char *argv)
{   
    char *prompt = "my_shell_$: ";
    char *exit = "exit"; 
    
    char *line;
    int number_of_cmd;
    char **parse_commands;
    Simple_cmd **cmd_table;

    while(1)
    {   
        printf("%s", prompt);
        line = get_line();
        if(!strcmp(line, exit))
        {   
            printf("your shell is closed\n");
            return -1;
        }

        number_of_cmd = number_of_commands(line);
        parse_commands = parser(line, number_of_cmd);

        for(int i = 0; i < number_of_cmd; i++)
        {
            char **cmd_tokens = simple_command_tokens(parse_commands[i]);
        }

        cmd_table = command_table(parse_commands, line);
        exec_command(cmd_table, number_of_cmd);
        
        memory_free(number_of_cmd, cmd_table, parse_commands, line);
     }




    return 0;
}