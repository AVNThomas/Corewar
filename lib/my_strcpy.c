/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** my_strcpy
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

unsigned char *my_strucpy(unsigned char *dest, unsigned char const *src,
int size)
{
    int i = 0;

    for (; i <= size; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
