#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void help_cmd(char **tokens)
{
        printf("cd - change directory\n");
        printf("mkdir - create new directory\n");
        printf("rmdir - delete directory(if it's empty)\n");
        printf("touch - create new file\n");
        printf("rm - delete file\n");
        printf("exit - close shell\n");
        printf("| - redirect\n> - add new file with data or replace data in existing file\n>> - add data in file\n");
}