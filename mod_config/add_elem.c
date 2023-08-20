#include <stdlib.h>
#include "cmd_mod.h"

List *add_elem(List *previos, char *command, char *help, void (*func_ptr) (char **tokens))
{
    List *temp, *ptr;
    temp = (List*)malloc(sizeof(List));
    ptr = previos->next;
    previos->next = temp;
    temp->cmd = command;
    temp->help = help;
    temp->func_ptr = func_ptr;
    temp->next = ptr;
    return temp;
}