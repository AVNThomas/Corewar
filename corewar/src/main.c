/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/my.h"
#include "../include/printf.h"

static int helper(char *prog, int ret_val)
{
    my_printf("USAGE:\n./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name]\n", prog);
    my_printf("DESCRIPTION:\n-dump nbr_cycle dumps the memory after the ");
    my_printf("nbr_cycle execution (if the round isn’t already over) with ");
    my_printf("the following format: 32 bytes/line in hexadecimal ");
    my_printf("(A0BCDEFE1DD3...)\n-n prog_number sets the next program’s ");
    my_printf("number. By default, the first free number in the parameter ");
    my_printf("order\n-a load_address sets the next program’s loading ");
    my_printf("address. When no address is specified, optimize the addresses ");
    my_printf("so that the processes are as far away from each other as ");
    my_printf("possible.\nThe addresses are MEM_SIZE modulo.\n");
    return(ret_val);
}

static int check_arg (int ac, char **argv)
{
    if (ac > 2 || ac == 1)
        return (helper(argv[0], 84));
    if (my_strncmp(argv[1], "-h", my_strlen("-h")) == 0)
        helper(argv[0], 0);
    return (0);
}

int main (int ac, char **argv)
{
    int ret_stat = check_arg(ac, argv);
    return (ret_stat);
}
