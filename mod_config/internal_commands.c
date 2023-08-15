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
    struct stat buff;
    // char **tokens = tokenss;

    if(!strcmp(tokens[0], "cd"))
    {
        char dir[20];   
        int cd = chdir(tokens[1]);
        getcwd(dir, 20);
    }
    else if(!strcmp(tokens[0], "newdir"))
    {       
        if(stat(tokens[1], &buff) == -1)
        {
            mkdir(tokens[1], 0777); 
        }
        else
            printf("directory exists\n");
    }
    else if(!strcmp(tokens[0], "rvdir"))
    {   
        if(stat(tokens[1], &buff) == 0)
        {
            rmdir(tokens[1]);
        }
        else
            printf("directory is not exist\n");
    }
    else if(!strcmp(tokens[0], "newfile"))
    {
        int file_d = open(tokens[1], O_RDWR | O_CREAT, 0777);
        close(file_d);
    }
    else if(!strcmp(tokens[0], "rvfile"))
    {
        remove(tokens[1]);
    }
    else if(!strcmp(tokens[0], "exit"))
    {   
        for(int i = 0; i < tokens_number; i++)
        {
            free(tokens[i]);
        }
        free(tokens);   
        free(line);
        printf("your shell is closed\n");
        exit(EXIT_SUCCESS);
    }
    else if(!strcmp(tokens[0], "help"))
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