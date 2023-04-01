#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"

Simple_cmd **command_table(char **tokens)
{   
    Simple_cmd sCom[2] = {{0, tokens}, {0, tokens}};

    Simple_cmd **simple_command = malloc(sizeof(Simple_cmd*)*2);
    simple_command[0] = malloc(sizeof(Simple_cmd)*1);
    simple_command[1] = malloc(sizeof(Simple_cmd)*1);
    
    simple_command[0] = &sCom[0];

    return simple_command;

}