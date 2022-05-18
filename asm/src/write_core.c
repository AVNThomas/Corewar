/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

static int get_size_prog(asm_list_t *list)
{
    int size = 0;

    for (; list != NULL; list = list->next);
    return (size);
}

static int write_header(int core, header_t *header, asm_list_t *list)
{
    header->prog_size = get_size_prog(list);
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        printf("%x\n", header->prog_name[i]);
    printf("%s\n", header->prog_name);
    printf("%d\n", header->prog_size);
    printf("%s\n", header->comment);
    printf("%x\n", header->magic);
    write(core, header, sizeof(header_t));
    return (EXIT_OK);
}

int write_core(int core, header_t *header, asm_list_t *list)
{
    if (write_header(core, header, list) == EXIT_ERR)
        return (EXIT_ERR);
    for (; list != NULL; list = list->next);
    return (0);
}
