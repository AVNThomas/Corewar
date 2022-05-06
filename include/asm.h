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

char *get_filename(char const *path);
int compile_asm(FILE *file_desc, char const *name);
int magic_header(int *header);
int name_header(char *asm_buff, char *name);
int comment_header(char *asm_buff, char *comment);
int write_struct(void);
#endif
