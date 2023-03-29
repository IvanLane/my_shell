#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_struct.h"

struct command_str **command_table(char **tokens)
{
    
    struct command_str **simple_command = malloc(sizeof(struct command_str)*2);
    simple_command[0] = malloc(sizeof(struct command_str));
    simple_command[0]->command = tokens;

}