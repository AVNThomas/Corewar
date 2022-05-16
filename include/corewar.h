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

typedef struct champions_s {
    char *name;
    char *comment;
    int number;
    FILE *ptr;
    struct champions_s *next;
} champions_t;

typedef struct vm_s {
    champions_t *champ;
} vm_t;

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
    vm_t *vm;
}corewar_t;

corewar_t *init_struct(corewar_t *g);
int hexa_to_decimal(char *hexa);
void find_header(corewar_t *g, char *file);
void get_first_function(corewar_t *g, char *file);
int decimal_to_binary(int decimal);
int arg_n(corewar_t *g, char **av, int i);
int arg_a(corewar_t *g, char **av, int i);
int hexa_to_decimal2(int hexa);
int arg_handler(corewar_t *g, int ac, char **av);
int arg_list_handler(corewar_t *g, char **av, int i);
args_t *add_node(args_t *list, char *name, int nb_player, int address);
void print_list(args_t *list);
champions_t *add_champ(champions_t *list, vm_header_t *header, args_t *arg);
void free_header(vm_header_t *header);
void print_champ(champions_t *champ);
void free_champ(champions_t *champ);
void free_arg(args_t *arg);
void free_all(corewar_t *g);
