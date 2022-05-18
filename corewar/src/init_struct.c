/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** init_struct
*/

#include "../include/corewar.h"

unsigned char *set_null_value(unsigned char *value, int size)
{
    for (int i = 0; i < size; i++)
        value[i] = 0;
    return (value);
}

corewar_t *init_struct(corewar_t *g)
{
    g->header = malloc(sizeof(vm_header_t));
    g->header = my_memset(g->header, 0, sizeof(vm_header_t));
    g->header->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    g->header->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    g->champ = NULL;
    g->vm = malloc(sizeof(char) * MEM_SIZE);
    g->vm = set_null_value(g->vm, MEM_SIZE);
    return (g);
}
