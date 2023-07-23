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
    char **pars = parser;
    char **toks = tokens;
    Simple_cmd **cmd_t = command_table;

    for(int i = 0; i < count; i++)
    {           
        free(cmd_t[i]);
        free(pars[i]);
        free(toks[i]);
    }
    
    free(pars);
    free(cmd_t);
    free(toks);
    
    if(infile > 0)
        free(infile);

    if(append > 0)
        free(append);

    char *ln = line;
    free(ln);

}