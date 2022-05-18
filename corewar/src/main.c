/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/corewar.h"

int helper(char *prog, int ret_val)
{
    my_printf("USAGE:\n%s [-dump nbr_cycle] [[-n prog_number] ", prog);
    my_printf("[-a load_address] prog_name]\n");
    my_printf("DESCRIPTION:\n-dump nbr_cycle dumps the memory after the ");
    my_printf("nbr_cycle execution (if the round isn’t already over) with ");
    my_printf("the following format: 32 bytes/line in hexadecimal ");
    my_printf("(A0BCDEFE1DD3...)\n-n prog_number sets the next program’s ");
    my_printf("number. By default, the first free number in the parameter ");
    my_printf("order\n-a load_address sets the next program’s loading ");
    my_printf("address. When no address is specified, optimize the ");
    my_printf("addresses so that the processes are as far away from");
    my_printf("each other as possible. The addresses are MEM_SIZE modulo.\n");
    return (ret_val);
}

void virtual_machine(corewar_t *g)
{
    place_champion(g);
    for (champions_t *tmp = g->champ; tmp != NULL; tmp = tmp->next) {
            advance_to_next_func(tmp, g);
    }
    while (1) {
        execute_champion(g);
    }
}

void fill_champ(corewar_t *g)
{
    args_t *tmp = NULL;

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

int main (int ac, char **argv)
{
    corewar_t *g = malloc(sizeof(corewar_t));
    int ret_value = 0;

    if (!g)
        return (84);
    g = my_memset(g, 0, sizeof(corewar_t));
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
