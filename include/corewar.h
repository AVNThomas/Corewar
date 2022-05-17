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

typedef struct args_s {
    char *name;
    int number;
    int load_adress;
    struct args_s *next;
} args_t;

typedef struct vm_header_s {
    int magic;
    char *name;
    int prog_size;
    char *comment;
}vm_header_t;

typedef struct corewar_s {
    vm_header_t *header;
    int nb_cycle;
    int nb_player;
    int load_adress;
    int tmp_nb_player;
    args_t *list;
}corewar_t;

corewar_t *init_struct(corewar_t *g);
int hexa_to_decimal(char *hexa);
void find_header(corewar_t *g, char *file);
void get_first_function(corewar_t *g, char *file);
int decimal_to_binary(int decimal);
int get_arg_alone(int function, FILE *ptr);
func_size_t *get_func_arg(int bitmask);
int get_arg(func_size_t *func_arg, int function, FILE *ptr);
int arg_n(corewar_t *g, char **av, int i);
int arg_a(corewar_t *g, char **av, int i);
int hexa_to_decimal2(int hexa);
int arg_handler(corewar_t *g, int ac, char **av);
int arg_list_handler(corewar_t *g, char **av, int i);
args_t *add_node(args_t *list, char *name, int nb_player, int address);
void print_list(args_t *list);
