/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_add
*/

#include "../../include/corewar.h"

void add_instru(champions_t *champ)
{
    champ->registre[champ->instru[2].value - 1] =
    champ->registre[champ->instru[0].value - 1] +
    champ->registre[champ->instru[1].value - 1];
}

void execute_add(corewar_t *g, champions_t *champ)
{
    add_instru(champ);
}
