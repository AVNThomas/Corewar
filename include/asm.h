/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** asm
*/

#ifndef _ASM_H
    #define _ASM_H
    #include "my.h"
    #include "op.h"
    #include "printf.h"
    #include <inttypes.h>
    #include <stdio.h>
    #define EXIT_ERR 84
    #define EXIT_OK 0

int generate_core(FILE *file, char const *name);

op_list_t *compile_core(op_list_t *list, char const *name);

int magic_header(int *header);
int name_header(char **asm_buff, char *name);
int comment_header(char **asm_buff, char *comment);
header_t *generate_header(header_t *header, char *asm_buff);

int write_core(int core, header_t *header, op_list_t *list);
#endif
