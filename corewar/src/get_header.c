/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** get_header
*/

#include "../include/corewar.h"

void find_header(corewar_t *g, char *file)
{
    int comment_pos = PROG_NAME_LENGTH + 8;
    FILE *ptr = fopen(file, "rb");

    fread(&g->header->magic, 4, 1, ptr);
    g->header->magic = __builtin_bswap32(g->header->magic);
    fread(g->header->name, PROG_NAME_LENGTH, 1, ptr);
    fseek(ptr, comment_pos, SEEK_SET);
    fread(&g->header->prog_size, 4, 1, ptr);
    g->header->prog_size = __builtin_bswap32(g->header->prog_size);
    fread(g->header->comment, COMMENT_LENGTH, 1, ptr);
    my_printf("magic = %x\nname = %s\nsize = %x\ncomment = %s\n",g->header->
    magic, g->header->name, g->header->prog_size,g->header->comment);
    fclose(ptr);
}
