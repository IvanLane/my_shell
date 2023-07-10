#include "unistd.h"

void cd_command(char **tokens)
{
        char dir[20];   
        int cd = chdir(tokens[1]);
        getcwd(dir, 20);
}