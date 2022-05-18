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
    int where = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] == '%' && tab[i][1] == ':') {
            tab[i] += 2;
            printf("%s\n", tab[i]);
            where = search_list_char(list_ref, tab[i]);
            tab[i] -= 2;
        }
        where = where;
    }
    free_double_array(tab);
    return (EXIT_OK);
}

int write_prog(int core, asm_list_t *list)
{
    asm_list_t *back = list;
    asm_list_t *list_ref = list;

    for (; list  != NULL; list = list->next, list_ref = back) {
        printf("%s\n", list->line);
        if (list->good)
            concombre(list, list_ref);
        write(core, &list->asm_line.code, sizeof(char));
    }
    list = back;
    return (EXIT_OK);
}
