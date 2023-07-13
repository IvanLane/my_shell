#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 1024
void display()
{
    char work_dir[BUFF_SIZE];
    if(!getcwd(work_dir, BUFF_SIZE))
    {
        perror("getcwd");
    }
    printf("%s$ ", work_dir);
}
