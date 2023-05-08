#ifndef COMMAND_STRUCT_H
#define COMMAND_STRUCT_H
#include "simple_command_tokens.h"

typedef struct Simple_cmd
    {   
        char *string;
        char** (*pnt_token_func) (char*);
        char **command_tokens;
   
    }Simple_cmd;

    Simple_cmd **command_table(char **parser, char *line);

#endif