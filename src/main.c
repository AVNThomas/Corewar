/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** main
*/

#include "corewar.h"

corewar_t *init_struct(corewar_t *cor)
{
    cor = my_memset(cor, 0, sizeof(corewar_t));
    return (cor);
}

int main(int ac, char **av)
{
    corewar_t *cor = malloc(sizeof(corewar_t));

    if (cor == NULL)
        return (84);
    cor = init_struct(cor);
    if (cor == NULL)
        return (84);
    free_all(cor);
    return (0);
}
