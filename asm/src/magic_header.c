/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

int magic_header(int *header)
{
    int ret_stat = EXIT_OK;
    int magic = COREWAR_EXEC_MAGIC;

    magic = __builtin_bswap32(magic);
    *header = magic;
    return (ret_stat);
}
