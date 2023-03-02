#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_line.h"
#include "parser.h"


void mem_free(char *str, char **tokens)
{
    free(str);
    free(tokens);
}


void exec_command(char **tokens)
{   
    char *path = getenv("PATH");
    char *path_token = strtok(path, ":");
    int command_length = strlen(tokens[0]);
    // printf("%d \n", strlen(tokens[0]));
    struct stat buffer;

    while(path_token != NULL)
    {
        char *real_path = malloc(command_length + strlen(path_token) + 2);
        // memset(real_path, 0, command_length + strlen(path_token) + 2);
        char *p = "\\bin\\ls";
   
        strcpy(real_path, path_token);
        strcat(real_path, "/");
        strcat(real_path, tokens[0]);
        strcat(real_path, "\0");
        // printf("%s", tokens[0]);
        if(stat(real_path, &buffer) == 0)
        {   
            printf("%s \n", real_path);
            // break;
            // if(execve(real_path, tokens, NULL) == -1)
            // {
                // perror("ERROR:");
            // }
        }

        free(real_path);
        path_token = strtok(NULL, ":");
    }

}

int main(int argc, char *argv)
{   
    char *prompt = "(my_shell) $:";
    char *exit = "exit"; 
    char *str;
    int number_of_tokens;
    char **tokens;
    
    // while(1)
    // {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, "exit\n"))
        {
            mem_free(str, tokens);
            printf("your shell is closed\n");
            return -1;
        }

        tokens = parser(str, &number_of_tokens);
        exec_command(tokens);
    // }


      
    return 0;
}