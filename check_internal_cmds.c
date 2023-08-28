#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_internal_cmds(char **tokens)
{   
    FILE *fd = fopen("/home/ivan/projects/shell/config", "r");
    if(fd == NULL)
    {
        perror("FILE");
    }

    fseek(fd, 0, SEEK_END);
    int size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    char buff[size];
    buff[size] = '\0';
    fread(buff, size/sizeof(char), sizeof(char), fd);

    if(strstr(buff, tokens[0]))
    {
        fclose(fd);
        return 1;
    }
    
    fclose(fd);
    return 0;
}

void start_modul(char ***tokens, char **line, int tokens_number)
{   

    void *handle = dlopen("/home/ivan/projects/shell/mod_config/libinternal.so", RTLD_LAZY);
    if(!handle)
    {   
        printf("%s", dlerror());
        exit(1);
    }

    void (*starter) (char**) = dlsym(handle, "start");
    starter(*tokens);

    dlclose(handle);

    free(*line);
    for(size_t i = 0; i < tokens_number; i++)
    {   
        free(tokens[0][i]);
    }
    free(*tokens);

}

