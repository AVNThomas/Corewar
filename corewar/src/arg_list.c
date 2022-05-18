/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_list
*/

#include "../include/corewar.h"

void add_node(args_t **list, char *name, int nb_player, int address)
{
    args_t *tmp = *list;
    args_t *new_node = malloc(sizeof(args_t));

    if (!(*list)) {
        *list = malloc(sizeof(args_t));
        (*list)->name = malloc(sizeof(char) * (my_strlen(name) + 1));
        (*list)->name = my_strcpy((*list)->name, name);
        (*list)->number = nb_player;
        (*list)->load_adress = address;
        (*list)->next = NULL;
        free(new_node);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    new_node->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    new_node->name = my_strcpy(new_node->name, name);
    new_node->number = nb_player;
    new_node->load_adress = address;
    new_node->next = NULL;
    tmp->next = new_node;
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

static int arg_n_a(corewar_t *g, char **av, int i)
{
    if (my_strcmp(av[i], "-n")) {
        i = arg_n(g, av, i);
        if (i == -1)
            return (-1);
    }
    if (my_strcmp(av[i], "-a")) {
        i = arg_a(g, av, i);
        if (i == -1)
            return (-1);
    }
    return (i);
}

int arg_list_handler(corewar_t *g, char **av, int i)
{
    g->list = NULL;
    i = arg_n_a(g, av, i);
    if (i == -1)
        return (-1);
    if (my_strncmp(my_revstr(av[i]), "roc.", 4)) {
        my_revstr(av[i]);
        g->nb_player++;
        if (g->tmp_nb_player != -1) {
            add_node(&g->list, av[i], g->tmp_nb_player,
            g->load_adress);
            g->tmp_nb_player = -1;
        } else
            add_node(&g->list, av[i], g->nb_player, g->load_adress);
    }
    return (i);
}

void free_arg(args_t *arg)
{
    args_t *tmp = NULL;

    while (arg) {
        tmp = arg;
        arg = arg->next;
        free(tmp->name);
        free(tmp);
    }
    free(arg);
}
