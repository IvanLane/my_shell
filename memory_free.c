#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#include "simple_command_tokens.h"
#include "get_path.h"
#include "parser.h"


void memory_free(int number_of_cmd, int tokens_numb, char **line, char ***parse_cmds, char ***tokens, Simple_cmd ***command_table, char *infile, char *append)
{   
    free(*line);
 
    for(size_t i = 0; i < number_of_cmd; i++)
    {
        free(parse_cmds[0][i]);
    }
    free(*parse_cmds);
    
    for(size_t i = 0; i < tokens_numb; i++)
    {
        free(tokens[0][i]);
    }
    free(*tokens);


    for(size_t i = 0; i < number_of_cmd; i++)
    {
        free(command_table[0][i]->path);
    }

    for(size_t i = 0; i < tokens_numb; i++)
    {
        free(command_table[0][i]->command_tokens);
    }


    // for(int i = 0; i < count; i++)
    // {   
    //     free(path[i]);        
        // free(cmd_t[i]);
        // free(pars[i]);
        // free(toks[i]);
    // }
    
    // free(path);
    // free(pars);
    // free(cmd_t);
    // free(toks);
    
    // if(infile > 0)
    //     free(infile);

    // if(append > 0)
    //     free(append);

}