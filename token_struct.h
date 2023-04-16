#ifndef COMMAND_STRUCT_H
#define COMMAND_STRUCT_H

typedef struct Simple_cmd
    {   
        short _pipe;
        char *string;   
    
    }Simple_cmd;

    Simple_cmd **parser(char *str, int *number);

#endif