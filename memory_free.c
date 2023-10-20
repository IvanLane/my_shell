#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#include "simple_command_tokens.h"
#include "get_path.h"
#include "parser.h"


void memory_free(int number_of_cmd, int tokens_numb, char **line, char ***parse_cmds, char ***tokens, Simple_cmd ***command_table, char **infile, char **append)
{   

    for(size_t i = 0; i < tokens_numb; i++)
    {
        free(tokens[0][i]);
    }
    free(*tokens);


    for(size_t i = 0; i < number_of_cmd; i++)
    {   
        if(command_table[0][i]->path != NULL)
            free(command_table[0][i]->path);
    }

    // FREE STRUCTS
    int cmd_tokens_numb = 1;
    int index = 0;
    for(size_t i = 0; i < number_of_cmd; i++)
    {   
        while(command_table[0][i]->string_cmd[index] != '\0')
        {   
            if(command_table[0][i]->string_cmd[index] == ' ')
                cmd_tokens_numb++;
            index++;
        }
        index = 0;
        for(size_t j = 0; j < cmd_tokens_numb; j++)
        {
            free(command_table[0][i]->command_tokens[j]);
        }
        free(command_table[0][i]->command_tokens);
    }

    for(size_t i = 0; i < number_of_cmd; i++)
    {
        free(command_table[0][i]);
    }
    free(*command_table);


        free(*line);
 
    for(size_t i = 0; i < number_of_cmd; i++)
    {
        free(parse_cmds[0][i]);
    }
    free(*parse_cmds);

    
    if(infile > 0)
        free(*infile);

    if(append > 0)
        free(*append);

}