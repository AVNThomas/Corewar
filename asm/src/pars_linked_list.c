/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** pars_linked_list.c
*/

#include "../include/asm.h"
#include "../include/op.h"

static int pars_code(asm_list_t *list, op_t **tab)
{
    char **line = my_spliter(list->line, ' ');
    int flag = 0;
    int j = 0;

    if (line == NULL)
        return (1);
    for (int i = 0; flag == 0 && line[j] != NULL;) {
        if (my_strcmp(tab[i]->mnemonique, line[j]) == 1) {
            list->asm_line.code = tab[i]->code;
            flag = 1;
        }
        i++;
        if (tab[i] == NULL) {
            i = 0;
            j++;
        }
    }
    if (flag == 0)
        return (1);
    return (0);
}

int pars_code_list(asm_list_t *list, op_t **tab)
{
    asm_list_t *backup = list;
    int check_error = 0;

    for (; list == NULL; list = list->next) {
        check_error = pars_code(list, tab);
        if (check_error == 1)
            return (1);
    }
    list = backup;
    return (0);
}