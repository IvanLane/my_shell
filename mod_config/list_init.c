#include <stdlib.h>
#include "cmd_mod.h"

List *init(char *command, char *help, void (*func_ptr) (char **tokens))
{
    // List *new_elem;
    List *new_elem = (List*)malloc(sizeof(List));
    new_elem->cmd = command;
    new_elem->help = help;
    new_elem->func_ptr = func_ptr;
    // new_elem->str = new_elem->func_ptr();
    new_elem->next = NULL;
    return new_elem;
}
