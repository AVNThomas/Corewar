/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** check_type.c
*/

#include "../include/asm.h"

static int check_register(char *word)
{
    int size = 0;

    if (word[0] != 'r')
        return (0);
    word++;
    size = my_atoi(word);
    if (size < 1 || size > REG_NUMBER)
        return (0);
    word--;
    return (1);
}

int check_type(char *word)
{
    if (check_register(word))
        return (1);
    else if (word[0] == '%')
        return (2);
    else
        return (3);
}