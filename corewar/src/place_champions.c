/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** place_champions
*/

#include "../include/corewar.h"

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    if (vm == NULL)
        return (NULL);
    return (vm);
}

void create_vm(corewar_t *g)
{
    g->vm = init_vm();
}
