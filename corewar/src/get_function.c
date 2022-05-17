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

int get_function(corewar_t *g, FILE *ptr)
{
    int mnemonic = 0;
    int function = 0;

    fread(&mnemonic, 1, 1, ptr);
    my_printf("mnemonic: %x\n", mnemonic);
    function = find_function(g, mnemonic);
    if (function == -1) {
        my_putstr("Error: unknown mnemonic\n");
        return (-1);
    }
    my_printf("function = %s\n", op_tab[function].mnemonique);
    my_printf("nb_argument = %d\n", op_tab[function].nbr_args);
    return (function);
}

int get_arg_alone(int function, FILE *ptr)
{
    int argument = 0;
    int arg = 0;
    int dir_size = 2;

    if (function == 0)
        dir_size = DIR_SIZE;
    if (op_tab[function].type[0] == T_DIR)
        arg = dir_size;
    if (op_tab[function].type[0] == T_REG)
        arg = 1;
    if (op_tab[function].type[0] == T_IND)
        arg = IND_SIZE;
    fread(&argument, 1, arg, ptr);
    argument = __builtin_bswap32(argument);
    printf("arg = %d\nargument = %x\n", arg, argument);
    return (arg);
}

int get_all_function(corewar_t *g, FILE *ptr)
{
    int function = 0;
    int bitmask = 0;
    func_size_t *func_size = malloc(sizeof(func_size_t));

    function = get_function(g, ptr);
    if (function == -1 )
        return (-1);
    if (op_tab[function].nbr_args != 1 || op_tab[function].code == 16)
        fread(&bitmask, 1, 1, ptr);
    else
        bitmask = 0;
    func_size = get_func_arg(bitmask);
    get_arg(func_size, function, ptr);
    return (0);
}

void get_first_function(corewar_t *g, char *file)
{
    FILE *ptr = fopen(file, "rb");
    int pos = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
    int value = 0;
    int func = 0;

    fseek(ptr, pos, SEEK_SET);
    while (get_all_function(g, ptr) != -1);
    fclose(ptr);
}
