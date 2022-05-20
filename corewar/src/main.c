/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/corewar.h"

void virtual_machine(corewar_t *g)
{
    place_champion(g);
    for (champions_t *tmp = g->champ; tmp != NULL; tmp = tmp->next)
        advance_to_next_func(tmp, g);
    while (1) {
        execute_champion(g);
    }
}

void fill_champ(corewar_t *g)
{
    args_t *tmp = NULL;

    printf("List of champions :\n");
    print_list(g->list);
    while (g->list != NULL) {
        find_header(g, g->list->name);
        get_first_function(g->list->name);
        add_champ(&g->champ, g->header, g->list);
        g->list = g->list->next;
    }
    g->list = tmp;
    print_champ(g->champ);
}

int main(int ac, char **argv)
{
    corewar_t *g = malloc(sizeof(corewar_t));
    int ret_value = 0;

    if (!g)
        return (84);
    g = my_memset(g, 0, sizeof(corewar_t));
    g->list = NULL;
    ret_value = arg_handler(g, ac, argv);
    if (ret_value == 84 || ret_value == 0) {
        free(g);
        return (ret_value);
    }
    g = init_struct(g);
    if (g == NULL) {
        my_free("sstt", g->header->name, g->header->comment, g->header, g);
        return (84);
    }
    fill_champ(g);
    virtual_machine(g);
    free_all(g);
    return (0);
}
