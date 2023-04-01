#ifndef COMMAND_STRUCT_H
#define COMMAND_STRUCT_H

typedef struct Simple_cmd
    {   
        int _pipe;
        char **tokens;   
    
    }Simple_cmd;

    Simple_cmd **command_table(char **tokens);

#endif