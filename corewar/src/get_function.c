/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_function
*/

#include "../include/corewar.h"

int find_function(corewar_t *g, int mnemonic)
{
    int i = 0;

    for (; i < 16; i++) {
        if (op_tab[i].code == mnemonic)
            return (i);
    }
    return (-1);
}

func_size_t *get_func_arg(int bitmask)
{
    int size = 0;
    int tmp = bitmask;
    func_size_t *func_size = malloc(sizeof(func_size_t));

    if (bitmask < 128) {
        tmp = bitmask + 128;
        func_size->arg[0] = 'r';
    } else {
        func_size->arg[0] = 'd';
        if (tmp & 64)
            func_size->arg[0] = 'i';
    }
    if (tmp & 32) {
        func_size->arg[1] = 'd';
        if (tmp & 16)
            func_size->arg[1] = 'i';
    } else
        func_size->arg[1] = 'r';
    if (tmp & 8) {
        func_size->arg[2] = 'd';
        if (tmp & 4)
            func_size->arg[2] = 'i';
    } else
        func_size->arg[2] = 'r';
    if (tmp & 2) {
        func_size->arg[3] = 'd';
        if (tmp & 1)
            func_size->arg[3] = 'i';
    } else
        func_size->arg[3] = 'r';
    return (func_size);
}

int get_function(corewar_t *g, FILE *ptr)
{
    int mnemonic = 0;
    int bitmask = 0;
    int function = 0;

    fread(&mnemonic, 1, 1, ptr);
    my_printf("mnemonic: %x\n", mnemonic);
    function = find_function(g, mnemonic);
    if (function == -1) {
        my_putstr("Error: unknown mnemonic\n");
        return (-1);
    }
    my_printf("function = %s\n", op_tab[function].mnemonique);
    return (function);
}

int get_arg(func_size_t *func_arg, int function, FILE *ptr)
{
    int arg_size = 0;
    int nbr_args = op_tab[function].nbr_args;
    int arg = 0;

    for (int i = 0; i < nbr_args; i++) {
        if (func_arg->arg[i] == 'r') {
            arg_size += T_REG;
            fread(&arg, T_REG, 1, ptr);
        }
        if (func_arg->arg[i] == 'd') {
            arg_size += T_DIR;
            fread(&arg, 1, T_DIR, ptr);
        }
        if (func_arg->arg[i] == 'i') {
            arg_size += T_IND;
            fread(&arg, 1, T_IND, ptr);
        }
        my_printf("func_arg->arg[%d] = %c\narg = %x\n", i, func_arg->arg[i], arg);
        arg = 0;
    }
    printf("arg_size = %d\n", arg_size);
    return (arg_size);
}

int get_all_function(corewar_t *g, FILE *ptr)
{
    int function = 0;
    char *arg = malloc(sizeof(char) * (g->header->prog_size + 1));
    int bitmask = 0;
    func_size_t *func_size = malloc(sizeof(func_size_t));

    function = get_function(g, ptr);
    if (function == -1)
        return;
    fread(&bitmask, 1, 1, ptr);
    func_size = get_func_arg(bitmask);
    get_arg(func_size, function, ptr);
    return (0);
}

void get_first_function(corewar_t *g, char *file)
{
    FILE *ptr = fopen(file, "rb");
    int pos = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;

    fseek(ptr, pos, SEEK_SET);
    while (get_all_function(g, ptr) != -1);
    fclose(ptr);
}
