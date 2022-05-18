/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

static int special_size(asm_list_t *list, char **tab)
{
    int i = 0;

    if (list->asm_line.code == 10)
        return (6);
    if (list->asm_line.code == 9 || list->asm_line.code == 12)
        return (3);
    if (list->asm_line.code == 1)
        return (5);
    i++;
    for (int j = 0; j != list->asm_line.nbr_args; j++) {
        if (check_type(tab[list->pos + j + 1]) == 1)
            i++;
        else
            i += 2;
    }
    return (i);
}

static int get_size_line(asm_list_t *list)
{
    char **tab = my_spliter(list->line, ' ');

    if (!(list->asm_line.nbr_args == 1 && list->asm_line.type[0] != 1))
        list->size++;
    if ((list->asm_line.code >= 9 && list->asm_line.code <= 12) ||
    list->asm_line.code == 1)
        list->size += special_size(list, tab);
    else {
        list->size++;
        for (int j = 0; j != list->asm_line.nbr_args; j++)
            list->size += check_type(tab[list->pos + j + 1]);
    }
    free_double_array(tab);
    return (list->size);
}

static int get_size_prog(asm_list_t *list)
{
    int size = 0;
    asm_list_t *backup = list;

    for (; list != NULL; list = list->next) {
        if (list->good == 1)
            size += get_size_line(list);
    }
    list = backup;
    size = __builtin_bswap32(size);
    return (size);
}

static int write_header(int core, header_t *header, asm_list_t *list)
{
    header->prog_size = get_size_prog(list);
    write(core, header, sizeof(header_t));
    return (EXIT_OK);
}

int write_core(int core, header_t *header, asm_list_t *list)
{
    if (write_header(core, header, list) == EXIT_ERR)
        return (EXIT_ERR);
    if (write_prog(core, list) == EXIT_ERR)
        return (EXIT_ERR);
    free(header);
    free_linked_list(list);
    return (EXIT_OK);
}
