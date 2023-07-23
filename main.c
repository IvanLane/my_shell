#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#include "headers.h"
#define SHELL_MAX_CMDS 8


int main(int argc, char *argv)
{   
    char *prompt = "my_shell: ";
    char *internal_cmds[SHELL_MAX_CMDS] = {"cd", "newdir", "rvdir", "newfile", "rvfile", "exit", "help", "cont"};

    char *infile_string;    
    char *append_infile_string;
    char *line;
    char **tokens;
    int number_of_cmd;
    char **parse_commands;
    Simple_cmd **cmd_table;

    signal(SIGTSTP, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    

    while(1)
    {   
        printf("%s", prompt);
        display();

        line = get_line();
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