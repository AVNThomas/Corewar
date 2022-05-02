/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** main
*/

#include "../include/asm.h"

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

static FILE *open_file(char *filepath)
{
    FILE *file = 0;

    file = fopen(filepath, "r");
    if (file == NULL) {
        my_printf("Error while opening file %s\n", filepath);
        return (NULL);
    }
    return (file);
}

int main (int ac, char **argv)
{
    int ret_stat = 0;
    FILE *file = 0;

    if (check_arg(ac, argv) != 0)
        return (EXIT_ERR);
    file = open_file(argv[1]);
    if (file == NULL)
        return (EXIT_ERR);
    fclose(file);
    return (ret_stat);
}
