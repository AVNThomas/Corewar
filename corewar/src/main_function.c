/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** main_function
*/

#include "../include/corewar.h"

static func_ptn_t func_pointer[16] = {
    {0, execute_live},
    {1, execute_ld},
    {2, execute_st},
    {3, execute_add},
    {4, execute_sub},
    {5, execute_and},
    {6, execute_or},
    {7, execute_xor},
    {8, execute_zjmp},
    {9, execute_ldi},
    {10, execute_sti},
    {11, execute_fork},
    {12, execute_lld},
    {13, execute_lldi},
    {14, execute_lfork},
    {15, execute_aff}
};

void execute_function(champions_t *champ, corewar_t *g)
{
    int mnemomic = 0;
}