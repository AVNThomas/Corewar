/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** execute_fork
*/

#include "../../include/corewar.h"

void fork_champ(champions_t *champ)
{
    champions_t *tmp = malloc(sizeof(champions_t));
    champions_t *next = champ->next;

    printf("champion %s forks\n", champ->name);
    tmp->name = my_strcpy_malloc(tmp->name, champ->name);
    tmp->comment = my_strcpy_malloc(tmp->comment, champ->comment);
    printf("champ code%s\nprog_size%d\n", champ->code, champ->prog_size);
    tmp->code = my_strucpy_malloc(tmp->code, champ->code, champ->prog_size);
    tmp->prog_size = champ->prog_size;
    tmp->number = champ->number;
    tmp->load_adress = champ->load_adress;
    tmp->carry = champ->carry;
    tmp->head = champ->head;
    tmp->tail = champ->tail;
    tmp->cycle_to_die = champ->cycle_to_die;
    FILE *ptr = NULL;
    tmp->cycles = 0;
    tmp->instruction = 0;
    for (int i = 0; i < REG_NUMBER; i++)
        tmp->registre[i] = champ->registre[i];
    tmp->next = next;
    champ->next = tmp;
}

void execute_fork(corewar_t *g, champions_t *champ)
{
    int adress = 0;
    fork_champ(champ);
    adress = (champ->head + champ->instru[0].value % IDX_MOD) % MEM_SIZE;
    champ = champ->next;
    champ->load_adress = adress;
    champ->head = adress;
    champ->tail = adress;
    write_char_in_mem(g, champ, champ->code, champ->prog_size);
    champ->head = champ->tail;
    advance_to_next_func(champ, g);
    return;
}
