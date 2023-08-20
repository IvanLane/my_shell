#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "cmd_mod.h"
    
void start(char **tokens)
{   
    int count = 0;

    char **cmd_string = commands();
    for(size_t i = 0; cmd_string[i] != NULL; i++)
    {
        count++;
    }

    void (*func_ptr[]) (char **tokens) = {cd_cmd, mkdir_cmd, rmdir_cmd, touch_cmd};

    List *cmd_ptrs[count]; 

    cmd_ptrs[0] = init(cmd_string[0], "cd_help", func_ptr[0]);

    for(size_t i = 1; cmd_string[i] != NULL; i++)
    {   
        cmd_ptrs[i] = add_elem(cmd_ptrs[i - 1], cmd_string[i], "mk_help", func_ptr[i]); 
    }

    List *ptr;
    ptr = cmd_ptrs[0];

    for(size_t i = 0; ptr != NULL; i++)
    {
        if(!strcmp(tokens[0], ptr->cmd))
        {
            void (*message) (char **tokens);
            message = ptr->func_ptr;
            message(tokens);
            break;
        }
        ptr = ptr->next;
    }

    
    // for(size_t i = 0; i < count; i++)
    // {
    //     printf("cmd[%ld] %s\n", i, cmd_string[0]);
    //     memset(cmd_string[i], 0, 10);
    //     printf("cmd [%ld] is free\n", i);
    // }
    free(cmd_string);
    // puts(cmd_string[0]);

    ptr = cmd_ptrs[0];
    for(size_t i = 0; i < count; i++)
    {   
        // printf("%s\n", cmd_ptrs[i]->cmd);
        free(cmd_ptrs[i]);
    }



}