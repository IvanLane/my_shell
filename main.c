#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "get_line.h"
#include "internal_commands.h"
#include "check_internal_cmds.h"
#include "infile.h"
#include "append_infile.h"
#include "number_of_command.h"
#include "parser.h"
#include "simple_command_tokens.h"
#include "tokens_number.h"
#include "token_struct.h"
#include "exec_command.h"
#include "memory_free.h"


int main(int argc, char *argv)
{   
    char *prompt = "my_shell: ";
    char *exit_shell = "exit"; 
    char *internal_cmds[3] = {"cd", "newdir", "rvdir"};

    char *infile_string;    
    char *append_infile_string;
    char *line;
    char **tokens;
    int number_of_cmd;
    char **parse_commands;
    Simple_cmd **cmd_table;

    while(1)
    {   
        printf("%s", prompt);
        char work_dir[100];
        getcwd(work_dir, 100);
        printf("%s$ ", work_dir);

        line = get_line();
        if(!strcmp(line, exit_shell))
        {   
            printf("your shell is closed\n");
            exit(EXIT_SUCCESS);
        } 

        tokens = simple_command_tokens(line);        
        number_of_cmd = number_of_commands(line);
        
        if(check_internal_cmds(internal_cmds, tokens) == 1)
        {
            internal_commands(tokens, line, tokens_number(line));
            continue;
        }

        infile_string = infile(line);
        append_infile_string = append_infile(line);        
        parse_commands = parser(line, number_of_cmd);
        cmd_table = command_table(parse_commands, line);
        exec_command(cmd_table, number_of_cmd, infile_string, append_infile_string);        
        memory_free(number_of_cmd, cmd_table, parse_commands, line, infile_string, append_infile_string, tokens);
     }




    return 0;
}