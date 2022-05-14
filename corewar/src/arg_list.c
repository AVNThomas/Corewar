/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_list
*/

#include "../include/corewar.h"

args_t *add_node(args_t *list, char *name, int nb_player, int address)
{
    args_t *new = malloc(sizeof(args_t));
    args_t *tmp = list;

    new->name = name;
    new->number = nb_player;
    new->load_adress = address;
    new->next = NULL;
    if (list == NULL)
        return (new);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

void print_list(args_t *list)
{
    args_t *tmp = list;

    while (tmp != NULL) {
        my_printf("Name = %s : ", tmp->name);
        my_printf("Number = %d : ", tmp->number);
        my_printf("Adress %d\n", tmp->load_adress);
        tmp = tmp->next;
    }
}

