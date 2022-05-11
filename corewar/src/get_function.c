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
    my_printf("mnemonic = %x\n", mnemonic);
    function = find_function(g, mnemonic);
    if (function == -1) {
        my_putstr("Error: unknown mnemonic\n");
        return (-1);
    }
    my_printf("function = %s\n", op_tab[function].mnemonique);
    return (function);
}

void get_first_function(corewar_t *g, char *file)
{
    FILE *ptr = fopen(file, "rb");
    int pos = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;

    fseek(ptr, pos, SEEK_SET);
    get_function(g, ptr);
}
