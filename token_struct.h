#ifndef COMMAND_STRUCT_H
#define COMMAND_STRUCT_H

typedef struct Simple_cmd
    {   
        char *string_cmd;
        char** (*pnt_token_func) (char*);
        char **command_tokens;
        char* (*pnt_get_path) (char **);
        char *path;
   
    }Simple_cmd;

    Simple_cmd **command_table(char **parser, char *line);

#endif