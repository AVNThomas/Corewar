/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_prog
*/

#include "../include/asm.h"

static int concombre(asm_list_t *list, asm_list_t *list_ref)
{
    char **tab = my_spliter(list->line, ' ');
    char where = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '%' && tab[i][1] == ':') {
            tab[i] += 2;
            where = search_list_char(list_ref, tab[i]);
            tab[i] -= 2;
        }
    }
    free_double_array(tab);
    return (where);
}

int write_prog(int core, asm_list_t *list)
{
    asm_list_t *back = list;
    asm_list_t *list_ref = list;
    char bit_mask = 0;
    int where = 0;

    for (; list  != NULL; list = list->next, list_ref = back) {
        printf("%s\n", list->line);
        if (list->good) {
            where = concombre(list, list_ref);
            for (int i = 0; i != where; i++, list_ref = list_ref->next)
                bit_mask += list_ref->size;
            printf("%x\n", bit_mask);
            write(core, &list->asm_line.code, sizeof(char));
            list_ref = back;
        }
        where = 0;
        bit_mask = 0;
    }
    list = back;
    return (EXIT_OK);
}
