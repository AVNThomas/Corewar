/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_prog
*/

#include "../include/asm.h"
#include <unistd.h>

static char where_in_list(char *word, asm_list_t *list_ref)
{
    char where = 0;

    word += 2;
    where = search_list_char(list_ref, word);
    word -= 2;
    return (where);
}

static void print_reg(char *arg, int core)
{
    char reg = 0;

    arg++;
    reg = my_atoi(arg);
    write(core, &reg, REG_SIZE);
    arg--;
}

static void print_ind(char *arg, int core, asm_list_t *ref)
{
    char ind[IND_SIZE] = {0};
    int where = 0;
    int size = 0;
    asm_list_t *back = ref;

    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        where = where_in_list(arg, ref);
        for (int i = 0; i != where; ref = ref->next, i++)
            size += ref->size;
    }
    else {
        arg++;
        *ind = my_atoi(arg);
        write(core, &ind, IND_SIZE);
        arg--;
    }
    ref = back;
}

static void print_dir(char *arg, int core, asm_list_t *ref)
{
    char dir[DIR_SIZE] = {0};
    int size = 0;
    int where = 0;
    asm_list_t *back = ref;

    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        where = where_in_list(arg, ref);
        for (int i = 0; i != where; ref = ref->next, i++)
            size += ref->size;
    }
    else {
        arg++;
        *dir = my_atoi(arg);
        write(core, &dir, DIR_SIZE);
        arg--;
    }
    ref = back;
}

int size_arg(int core, asm_list_t *list, asm_list_t *ref_list)
{
    char **tab = my_spliter(list->line, ' ');
    asm_list_t *back = ref_list;
    char *arg = NULL;

    for (int i = 0; i != list->asm_line.nbr_args; i++) {
        arg = tab[list->pos + i + 1];
        if (get_size_elem(arg, list->asm_line.code) == REG_SIZE)
            print_reg(arg, core);
        if (get_size_elem(arg, list->asm_line.code) == IND_SIZE)
            print_ind(arg, core, ref_list);
        if (get_size_elem(arg, list->asm_line.code) == DIR_SIZE)
            print_dir(arg, core, ref_list);
        ref_list = back;
    }
    free_double_array(tab);
    return (EXIT_OK);
}
