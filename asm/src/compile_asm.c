/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** compile_asm
*/

#include "../include/asm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static int create_core_file(char const *name)
{
    int fd = 0;

    fd = open(name , O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
              S_IRGRP | S_IROTH);
    return (fd);
}

int compile_asm(FILE *asm_fd, char const *name)
{
    int core_fd = create_core_file(name);
    int ret_stat = EXIT_OK;
    char *asm_buff = NULL;

    asm_buff = getline_file(asm_fd);
    my_printf("%s", asm_buff);
    if (core_fd == -1)
        return (EXIT_ERR);
    free(asm_buff);
    close(core_fd);
    return (ret_stat);
}
