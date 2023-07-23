#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#define BUFF_SIZE PATH_MAX

void display()
{
    char work_dir[BUFF_SIZE];
    if(!getcwd(work_dir, BUFF_SIZE))
    {
        perror("getcwd");
    }
    printf("%s$ ", work_dir);
}
