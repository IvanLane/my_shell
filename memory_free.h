#ifndef MEMORY_FREE_H
#define MEMOTY_FREE_H

void memory_free(int number_of_cmd, int tokens_numb, char **line, char ***parse_cmds, char ***tokens, Simple_cmd ***command_table, char *infile, char *append);

#endif