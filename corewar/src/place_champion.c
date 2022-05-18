/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** place_champion
*/

#include "../include/corewar.h"

void place_champion(corewar_t *g)
{
    int load_adress[g->nb_player];
    champions_t *tmp = g->champ;

    for (int i = 0; i < g->nb_player; i++) {
        load_adress[i] = MEM_SIZE / g->nb_player * i;
    }
    for (int i = 0; i < g->nb_player; i++) {
        tmp->load_adress = load_adress[i];
        tmp->head = load_adress[i];
        tmp->tail = load_adress[i];
        write_char_in_mem(g, tmp, tmp->code, tmp->prog_size);
        tmp = tmp->next;
    }
}
