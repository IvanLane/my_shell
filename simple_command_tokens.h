#ifndef SIMPLE_COMMAND_TOKENS
#define SIMPLE_COMMAND_TOKENS
#include "token_struct.h"  

char **simple_command_tokens(Simple_cmd **command_table, int pid_numb, char *command_string);

#endif