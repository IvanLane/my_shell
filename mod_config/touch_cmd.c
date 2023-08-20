#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void touch_cmd(char **tokens)
{
        int file_d = open(tokens[1], O_RDWR | O_CREAT, 0777);
        close(file_d);
}