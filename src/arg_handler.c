/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** arg_handler
*/

#include "corewar.h"

void arg_handler(corewar_t *cor, int argc, char **argv)
{
    char *description = NULL;

    if (argc <= 1) {
        description = getline_file("description/description.txt");
        my_printf("%e\n", description);
        my_free("st", description, cor);
        exit(84);
    } else if (my_strcmp(argv[1], "-h")) {
        description = getline_file("description/description.txt");
        my_printf("%s\n", description);
        my_free("st", description, cor);
        exit(0);
    }
}
