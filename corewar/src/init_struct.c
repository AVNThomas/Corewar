/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** init_struct
*/

#include "../include/corewar.h"

corewar_t *init_struct(corewar_t *g)
{
    g = my_memset(g, 0, sizeof(corewar_t));
    g->header = malloc(sizeof(vm_header_t));
    g->header = my_memset(g->header, 0, sizeof(vm_header_t));
    g->header->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    g->header->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    return (g);
}
