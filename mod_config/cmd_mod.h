#ifndef CMD_MOD
#define CMD_MOD

typedef struct List
{
    char *cmd;
    char *help;
    void (*func_ptr) (char **tokens);
    struct List *next;
}List;


char **commands(void);
void cd_cmd(char **tokens);
void mkdir_cmd(char **tokens);
void rmdir_cmd(char **tokens);
void touch_cmd(char **tokens);
void rm_cmd(char **tokens);
void help_cmd(char **tokens);
void start(char **tokens);

List *init(char *command, char *help, void (*func_ptr) (char **tokens));
List *add_elem(List *previos, char *command, char *help, void (*func_ptr) (char **tokens));



#endif