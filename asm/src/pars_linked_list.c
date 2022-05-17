/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** pars_linked_list.c
*/

#include "../include/asm.h"

static int pars_code(asm_list_t *list)
{
    char **line = my_spliter(list->line, ' ');
    int j = 0;

    list->position = -1;
    if (line == NULL)
        return (EXIT_ERR);
    for (int i = 0; list->position == -1 && line[j] != NULL; i++) {
        if (op_tab[i].nbr_args == 0) {
            i = 0;
            j++;
        }
        if (my_strcmp(op_tab[i].mnemonique, line[j]) == 1) {
            list->asm_line = op_tab[i];
            list->position = j;
        }
    }
    free_double_array(line);
    if (list->position == -1)
        return (EXIT_ERR);
    return (0);
}

int pars_code_list(asm_list_t *list)
{
    asm_list_t *backup = list;
    int check_error = 0;

    for (; list == NULL; list = list->next) {
        check_error = pars_code(list);
        if (check_error == EXIT_ERR)
            return (EXIT_ERR);
    }
    list = backup;
    return (0);
}
