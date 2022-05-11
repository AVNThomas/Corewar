/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** corewar
*/

#ifndef _COREWAR_H_
    #define _COREWAR_H_
    #include "my.h"
    #include "printf.h"
    #include "op.h"
#endif

typedef struct vm_header_s {
    int magic;
    char *name;
    int prog_size;
    char *comment;
}vm_header_t;

typedef struct corewar_s {
    vm_header_t *header;
}corewar_t;

corewar_t *init_struct(corewar_t *g);
void find_header(corewar_t *g, char *file);
void get_first_function(corewar_t *g, char *file);
