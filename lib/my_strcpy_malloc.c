/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** my_strcpy_malloc
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strcpy_malloc(char *dest, char const *src)
{
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    dest = my_memset(dest, 0, strlen(src) + 1);
    dest = my_strcpy(dest, src);
    return (dest);
}
