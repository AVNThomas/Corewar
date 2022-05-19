/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_zjmp
*/

#include "../../include/corewar.h"

void execute_zjmp(corewar_t *g, champions_t *champ)
{
    short value = 0;

    if (champ->instru[0].rid != 'd')
        return;
    printf("zjmp %d\n", champ->instru[0].value);
    if (champ->carry == 0)
        return;
    value = (short)champ->instru[0].value;
    printf("head %d\n", champ->head);
    champ->head = (champ->head + value % IDX_MOD) % MEM_SIZE;
    printf("head %d\n", champ->head);
}
