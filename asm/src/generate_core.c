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

static header_t *init_header(void)
{
    header_t *header = malloc(sizeof(header_t));

    if (header == NULL)
        return (NULL);
    my_memset(header->comment, 0, COMMENT_LENGTH + 1);
    my_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
    header->magic = 0;
    header->prog_size = 0;
    return (header);
}

static int compile_asm(char *asm_buff, int core_fd)
{
    core_fd = core_fd;
    int ret_stat = EXIT_OK;
    header_t *header = init_header();
    asm_list_t *list = NULL;

    if (header == NULL)
        return (EXIT_ERR);
    header = generate_header(header, asm_buff);
    if (header == NULL)
        return (EXIT_ERR);
    list = compile_core(list, asm_buff);
    if (list == NULL) {
        free(header);
        return (EXIT_ERR);
    }
    pars_code_list(list, op_tab);
    free(header);
    free_linked_list(list);
    // write_core(int core, header_t *header, op_list_t *list) --> free all elem
    return (ret_stat);
}

int generate_core(FILE *asm_fd, char const *name)
{
    int core_fd = create_core_file(name);
    int ret_stat = EXIT_OK;
    char *asm_buff = NULL;

    if (core_fd == -1)
        return (EXIT_ERR);
    asm_buff = getline_file(asm_fd);
    if (asm_buff == NULL) {
        close(core_fd);
        return (EXIT_ERR);
    }
    ret_stat = compile_asm(asm_buff, core_fd);
    free(asm_buff);
    close(core_fd);
    return (ret_stat);
}
