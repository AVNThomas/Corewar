/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** get_size.c
*/

#include "../include/asm.h"

static int special_size_elem(char *word, int type)
{
    int i = 0;

    if (type == 9 || type == 12)
        return (2);
    if (type == 1)
        return (4);
    if (check_type(word) == 1)
        i = 1;
    else
        i = 2;
    return (i);
}


int get_size_elem(char *word, int type)
{
    int i = 0;

    if ((type >= 9 && type <= 12) || type == 1)
        return (special_size_elem(word, type));
    else
        i = check_type(word);
    return (i);
}