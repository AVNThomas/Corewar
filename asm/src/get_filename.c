/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** get_filename
*/

#include "../include/asm.h"

char *get_filename(char const *path)
{
    int size = my_strlen(path) + my_strlen(".cor\0") + 1;
    char *name = malloc(sizeof(char) * size);

    if (name == NULL)
        return (NULL);
    if (path == NULL) {
        free(name);
        return (NULL);
    }
    name = my_memset(name, 0, size);
    name = my_strcpy(name, path);
    for (int i = 0; name[i] != '\0'; i++)
        if (name[i + 1] != '\0' && name[i] == '.') {
            name[i + 1] = '.';
            name[i] = '\0';
        }
    my_printf("size = %d\nsize size = %d\n", my_strlen(name), size);
    name = my_strcat(name, ".cor");

    return (name);
}
