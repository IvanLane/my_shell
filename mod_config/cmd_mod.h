#ifndef CMD_MOD
#define CMD_MOD

typedef struct List
{
    char *cmd;
    char *help;
    void (*func_ptr) (void);
    struct List *next;
}List;


char **command(void);
void cd_cmd(void);


#endif