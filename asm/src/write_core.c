/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

int write_core(int core, header_t *header, asm_list_t *list)
{
    write(core, header, sizeof(*header));
    for (; list != NULL; list = list->next)
        printf("\n");
    return (0);
}
