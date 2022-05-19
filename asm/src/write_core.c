/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

static int write_arg(int core, asm_list_t *list, asm_list_t *ref)
{
    asm_list_t *back = ref;

    for (; list != NULL; list = list->next) {
        printf("line = %s\n", list->line);
        if (list->good) {
            printf("code = %x\n", list->asm_line.code);
            write(core, &list->asm_line.code, sizeof(char));
        }
        size_arg(core, list, ref);
        printf("\n");
    }
    list = back;
    ref = back;
    return (EXIT_OK);
}

int write_prog(int core, asm_list_t *list)
{
    asm_list_t *back = list;
    asm_list_t *list_ref = list;

    write_arg(core, list, list_ref);
    list = back;
    return (EXIT_OK);
}

static int write_header(int core, header_t *header, asm_list_t *list)
{
    header->prog_size = get_size_prog(list);
    write(core, header, sizeof(header_t));
    return (EXIT_OK);
}

int write_core(int core, header_t *header, asm_list_t *list)
{
    if (write_header(core, header, list) == EXIT_ERR)
        return (EXIT_ERR);
    if (write_prog(core, list) == EXIT_ERR)
        return (EXIT_ERR);
    free(header);
    free_linked_list(list);
    return (EXIT_OK);
}
