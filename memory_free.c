// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #include "token_struct.h"
// #include "simple_command_tokens.h"
// #include "get_path.h"


// void memory_free(Simple_cmd **command_table, char **parser, char *line)
// {   
//     int count = command_table[0]->number_of_commands;

//     for(int i = 0; i < count; i++)
//     {   
//         free(command_table[i]);
//         free(parser[i]);
//     }
//     free(command_table);
//     free(parser);

//     free(line);

// }