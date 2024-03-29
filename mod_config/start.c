#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "cmd_mod.h"
    
void start(char **tokens)
{   
    int count = 6;

    char **cmd_string = commands();

    void (*func_ptr[]) (char **tokens) = {cd_cmd, mkdir_cmd, rmdir_cmd, touch_cmd, rm_cmd, help_cmd};


    List **cmd_ptrs = malloc(sizeof(List*) * count);

    cmd_ptrs[0] = init(cmd_string[0], "cd_help", func_ptr[0]);

    for(size_t i = 1; i < count; i++)
    {   
        cmd_ptrs[i] = add_elem(cmd_ptrs[i - 1], cmd_string[i], "mk_help", func_ptr[i]); 
    }

    List *ptr;
    ptr = cmd_ptrs[0];

    for(size_t i = 0; i < count; i++)
    {
        if(!strcmp(tokens[0], ptr->cmd))
        {
            void (*cmd_func_ptr) (char **tokens);
            cmd_func_ptr = ptr->func_ptr;
            cmd_func_ptr(tokens);
            break;
        }
        ptr = ptr->next;
    }

    ptr = cmd_ptrs[0];
    for(size_t i = 0; i < count; i++)
    {
        free(cmd_ptrs[i]);
    }
    free(cmd_ptrs);
    
    for(size_t i = 0; i < count; i++)
    {   
        free(cmd_string[i]);
    }
    free(cmd_string);

}