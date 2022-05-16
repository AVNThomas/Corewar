/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** pars_linked_list.c
*/

#include "../include/asm.h"

static asm_list_t *stock_struct(asm_list_t *list, op_t *tab)
{
    list->asm_line.code = tab->code;
    list->asm_line.nbr_args = tab->nbr_args;
    list->asm_line.type[0] = tab->type[0];
    list->asm_line.type[1] = tab->type[1];
    list->asm_line.type[2] = tab->type[2];
    list->asm_line.type[3] = tab->type[3];
    return (list);
}

static int pars_code(asm_list_t *list, op_t **tab)
{
    char **line = my_spliter(list->line, ' ');
    int flag = 0;
    int j = 0;

    if (line == NULL)
        return (EXIT_ERR);
    for (int i = 0; flag == 0 && line[j] != NULL; i++) {
        if (tab[i]->nbr_args == 0) {
            i = 0;
            j++;
        }
        if (my_strcmp(tab[i]->mnemonique, line[j]) == 1) {
            list = stock_struct(list, tab[i]);
            flag = 1;
        }
    }
    free_double_array(line);
    if (flag == 0)
        return (EXIT_ERR);
    return (0);
}

int pars_code_list(asm_list_t *list, op_t **tab)
{
    asm_list_t *backup = list;
    int check_error = 0;

    for (; list == NULL; list = list->next) {
        check_error = pars_code(list, tab);
        if (check_error == EXIT_ERR)
            return (EXIT_ERR);
    }
    list = backup;
    return (0);
}
