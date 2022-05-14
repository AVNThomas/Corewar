/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** corewar
*/

#ifndef _COREWAR_H_
    #define _COREWAR_H_
    #include "my.h"
    #include "printf.h"
    #include "op.h"
#endif

typedef struct l_args_s {
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
int hexa_to_decimal2(int hexa);
int arg_handler(corewar_t *g, int ac, char **av);

args_t *add_node(args_t *list, char *name, int nb_player, int address);
void print_list(args_t *list);
