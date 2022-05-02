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
    my_printf("USAGE:\n%s [-h] filename.[s]\n", prog);
    my_printf("DESCRIPTION:\nCompile filename.s to ");
    my_printf("filename.core for corewar Virtual Machine\n");
    return (ret_val);
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
