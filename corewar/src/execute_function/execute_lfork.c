/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_lfork
*/

#include "../../include/corewar.h"

void execute_lfork(corewar_t *g, champions_t *champ)
{
    int adress = 0;
    fork_champ(champ);
    adress = (champ->head + champ->instru[0].value) % MEM_SIZE;
    champ = champ->next;
    champ->load_adress = adress;
    champ->head = adress;
    champ->tail = adress;
    write_char_in_mem(g, champ, champ->code, champ->prog_size);
    champ->head = champ->tail;
    advance_to_next_func(champ, g);
    printf("fork\n");
    return;
}
