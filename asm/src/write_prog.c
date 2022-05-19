/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_prog
*/

#include "../include/asm.h"

static char where_in_list(char *word, asm_list_t *list_ref)
{
    char where = 0;

    if (word[0] == LABEL_CHAR && word[1] == DIRECT_CHAR) {
        word += 2;
        where = search_list_char(list_ref, word);
        word -= 2;
    }
    return (where);
}

static void print_reg(char *arg, int core)
{
    char reg = 0;
    arg++;
    reg = my_atoi(arg);
    printf("reg --> %x\n", reg);
    write(core, &reg, REG_SIZE);
    arg--;
}

static void print_ind(char *arg, int core, asm_list_t *ref)
{
    printf("ind --> %s\n", arg);
    printf("%d\n", where_in_list(arg, ref));
    core = core;
}

static void print_dir(char *arg, int core, asm_list_t *ref)
{
    printf("direct --> %s\n", arg);
    printf("%d\n", where_in_list(arg, ref));
    core = core;
}

int size_arg(int core, asm_list_t *list, asm_list_t *ref_list)
{
    char **tab = my_spliter(list->line, ' ');
    char where = 0;
    asm_list_t *back = ref_list;
    char *arg = NULL;

    for (int i = 0; i != list->asm_line.nbr_args; i++) {
        arg = tab[list->pos + i + 1];
        printf("arg:  %s ", arg);
        if (get_size_elem(arg, list->asm_line.code) == REG_SIZE)
            print_reg(arg, core);
        if (get_size_elem(arg, list->asm_line.code) == DIR_SIZE)
            print_dir(arg, core, ref_list);
        if (get_size_elem(arg, list->asm_line.code) == IND_SIZE)
            print_ind(arg, core, ref_list);
        ref_list = back;
    }
    free_double_array(tab);
    return (where);
}
