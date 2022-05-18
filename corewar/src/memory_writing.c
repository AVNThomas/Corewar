/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** memory_writing
*/

#include "../include/corewar.h"

void write_char_in_mem(corewar_t *g, champions_t *champ, unsigned char *value, int size)
{
    for (int i = 0; i <= size; i++) {
        g->vm[champ->head] = value[i];
        champ->head++;
        if (champ->head == MEM_SIZE)
            champ->head = 0;
    }
}
