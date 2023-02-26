#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_line.h"
#include "parser.h"

int main(int argc, char *argv)
{   
    char *prompt = "(my_shell) $:";
    char *exit = "exit"; 

    char *str;
    int number_of_tokens;
    char **tokens;

    while(1)
    {   
        printf("%s", prompt);
        str = get_line();
        if(!strcmp(str, "exit\n"))
        {
            printf("your shell is closed\n");
            free(str);
            return -1;
        }

        tokens = parser(str, &number_of_tokens);
    }


    puts(str);
    
   
    return 0;
}