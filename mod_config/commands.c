#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "cmd_mod.h"

#define MAX 3

char **commands()
{                           
    char **buff = malloc(sizeof(char*)*MAX);
    for(size_t i = 0; i < MAX; i++)
    {   
        buff[i] = malloc(sizeof(char) * MAX);
        memset(buff[i], 0, 10);                                 
    }
    buff[0] = "cd_cmd";
    buff[1] = "mkdir_cmd";
    buff[2] = NULL;                         
    // buff[3] = "rm_cmd"; 
    // buff[4] = "fk_cmd";
    // buff[5] = NULL;
    return buff;    
}