#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_line.h"

int main(int argc, char *argv)
{   
    char *prompt = "(my_shell) $:";
    char *exit = "exit"; 

    printf("%s", prompt);
    char *str;
    while(1)
    {
        str = get_line();
        printf("%s \n", str);

        if(!strcmp(str, "exit\n"))
        {
            printf("your shell is closed\n");
            return -1;
        }
    }


    free(str);
   
    return 0;
}