/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_zjmp
*/

#include "../../include/corewar.h"

void execute_zjmp(corewar_t *g, champions_t *champ)
{
    if (champ->instru[0].rid != 'd')
        return;
    if (champ->carry == 0)
        return;
    champ->head = (champ->head + champ->instru[0].value % IDX_MOD) % MEM_SIZE;
}
