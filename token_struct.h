#ifndef COMMAND_STRUCT_H
#define COMMAND_STRUCT_H

typedef struct Simple_cmd
    {   
        short number_of_commands;
        short _pipe;
        char *string;   
    
    }Simple_cmd;

    Simple_cmd **command_table(char **parser, char *line);

#endif