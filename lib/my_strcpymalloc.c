/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** my_strcpymalloc
*/

#include "../include/my.h"

char *my_strcpy_malloc(char *dest, char const *src)
{
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    dest = my_memset(dest, 0, my_strlen(src) + 1);
    dest = my_strcpy(dest, src);
    return (dest);
}
