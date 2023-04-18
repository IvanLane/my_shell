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
#include "parser.h"
#include "memory_free.h"



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
        table = command_table(parse_commands, str);
        exec_command(table);

        memory_free(table, parse_commands, str);  
    
    }


      
    return 0;
}