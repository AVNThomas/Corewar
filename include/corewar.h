/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** corewar
*/

#pragma once

#include "my.h"
#include "printf.h"
#include "op.h"

typedef struct func_size_s {
    char arg[4];
} func_size_t;

typedef struct vm_header_s {
    int magic;
    char *name;
    int prog_size;
    char *comment;
}vm_header_t;

typedef struct corewar_s {
    vm_header_t *header;
}corewar_t;

corewar_t *init_struct(corewar_t *g);
int hexa_to_decimal(char *hexa);
void find_header(corewar_t *g, char *file);
void get_first_function(corewar_t *g, char *file);
int decimal_to_binary(int decimal);
int get_arg_alone(int function, FILE *ptr);
func_size_t *get_func_arg(int bitmask);
int get_arg(func_size_t *func_arg, int function, FILE *ptr);
int hexa_to_decimal2(int hexa);
