/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

static void get_bytemask(asm_list_t *list, int core)
{
    unsigned char bitmask = 0;

    if (list->asm_line.nbr_args == 1 && list->asm_line.type[0] != 1)
        return;
    for (int i = 0; i < list->asm_line.nbr_args; i++) {
        bitmask = bitmask << 2;
        if (check_type(list->tab[list->pos + i + 1]) == REG_SIZE)
            bitmask += 1;
        if (check_type(list->tab[list->pos + i + 1]) == DIR_SIZE)
            bitmask += 2;
        if (check_type(list->tab[list->pos + i + 1]) == IND_SIZE)
            bitmask += 3;
        my_printf("bitmask %b\n", bitmask);
    }
    printf("bitmask %x\n", bitmask);
    write(core, &bitmask, sizeof(char));
    return;
}

static int write_arg(int core, asm_list_t *list, asm_list_t *ref)
{
    asm_list_t *back = ref;
    int ret_stat = EXIT_OK;

    for (; list != NULL; list = list->next) {
        if (!list->good)
            continue;
        if (write(core, &list->asm_line.code, sizeof(char)) == -1)
            return (EXIT_ERR);
        get_bytemask(list, core);
        size_arg(core, list, ref);
        ref = back;
    }
    list = back;
    return (ret_stat);
}

int write_prog(int core, asm_list_t *list)
{
    asm_list_t *back = list;
    asm_list_t *list_ref = list;

    if (write_arg(core, list, list_ref) == EXIT_ERR) {
        list = back;
        return (EXIT_ERR);
    }
    list = back;
    return (EXIT_OK);
}

static int write_header(int core, header_t *header, asm_list_t *list)
{
    if (list != NULL) {
        header->prog_size = get_size_prog(list);
    }
    if (write(core, header, sizeof(header_t)) == -1)
        return (EXIT_ERR);
    return (EXIT_OK);
}

int write_core(int core, header_t *header, asm_list_t *list)
{

    if (write_header(core, header, list) == EXIT_ERR)
        return (EXIT_ERR);
    if (list != NULL)
        if (write_prog(core, list) == EXIT_ERR)
            return (EXIT_ERR);
    free(header);
    free_linked_list(list);
    return (EXIT_OK);
}
