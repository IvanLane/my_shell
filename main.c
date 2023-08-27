#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

#include "headers.h"

int main(int argc, char *argv)
{   
    char *prompt = "my_shell: ";
    char *line;
    char **tokens;
    int number_of_cmd;
    int tokens_numb;
    char *infile_string;    
    char *append_infile_string;
    char **parse_commands;
    Simple_cmd **cmd_table;

    signal(SIGTSTP, SIG_IGN);
    signal(SIGINT, SIG_IGN);
    
    while(1)
    {   
        printf("%s", prompt);
        display();

        line = get_line();
        exit_stat(&line);
        tokens = simple_command_tokens(line);
        number_of_cmd = number_of_commands(line);
        tokens_numb = tokens_number(line);

        if(check_internal_cmds(tokens))
        {   
            start_modul(tokens, line, tokens_numb);
            continue;
        }

        infile_string = infile(line);
        append_infile_string = append_infile(line);        
        parse_commands = parser(line, number_of_cmd);
        cmd_table = command_table(parse_commands, line);
        exec_command(cmd_table, number_of_cmd, infile_string, append_infile_string);    
        memory_free(number_of_cmd, tokens_numb, &line, &parse_commands, &tokens, &cmd_table, infile_string, append_infile_string);
    }    

    return 0;
}