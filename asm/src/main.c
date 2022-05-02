/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/asm.h"
#include <stdlib.h>
#include <unistd.h>

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
        return (helper(argv[0], EXIT_ERR));
    if (my_strncmp(argv[1], "-h", my_strlen("-h")) == 0)
        helper(argv[0], EXIT_OK);
    return (EXIT_OK);
}

static int open_file(char *filepath)
{
    int file = 0;

    file = open(filepath, O_RDONLY);
    if (file == -1) {
        my_printf("Error while opening file %s\n", filepath);
        return (-1);
    }
    return (file);
}

int main (int ac, char **argv)
{
    int ret_stat = 0;
    int file = 0;

    if (check_arg(ac, argv) != 0)
        return (EXIT_ERR);
    file = open_file(argv[1]);
    if (file == -1)
        return (EXIT_ERR);
    close(file);
    return (ret_stat);
}
