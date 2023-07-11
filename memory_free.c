#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"
#include "simple_command_tokens.h"
#include "get_path.h"
#include "parser.h"


void memory_free(int number_of_cmd, Simple_cmd **command_table, char **parser, char *line, char *infile, char *append, char  **tokens)
{   
    int count = number_of_cmd;

    for(int i = 0; i < count; i++)
    {           
        free(command_table[i]);
        free(parser[i]);
    }
    free(parser);
    free(command_table);
    
    if(infile > 0)
        free(infile);

    if(append > 0)
        free(append);

    
    for(int i = 0; i < count; i++)
    {
        free(tokens[i]);
    }
    free(tokens);

    free(line);

}