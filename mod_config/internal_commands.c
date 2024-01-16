#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

void internal_commands(char **tokens, char *line, int tokens_number)
{   

    if(!strcmp(tokens[0], "help"))
    {
        printf("cd - change directory\n");
        printf("newdir - create new directory\n");
        printf("rvdir - delete directory(if it's empty)\n");
        printf("newfile - create new file\n");
        printf("rvfile - delete file\n");
        printf("exit - close shell\n");
        printf("| - redirect\n> - add new file with data or replace data in existing file\n>> - add data in file\n");
    }
    else if(!strcmp(tokens[0], "cont"))
    {   
        kill(atoi(tokens[1]), SIGCONT);
    } 
    else if(!strcmp(tokens[0], "stop"))
    {   
        kill(atoi(tokens[1]), SIGSTOP);
    } 
    else if(!strcmp(tokens[0], "kill_p"))
    {   
        kill(atoi(tokens[1]), SIGKILL);
    } 


    for(int i = 0; i < tokens_number; i++)
            {
                free(tokens[i]);
            }
            free(tokens);   
            free(line);
}