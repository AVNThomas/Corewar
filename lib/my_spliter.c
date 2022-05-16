/*
** EPITECH PROJECT, 2021
** lib/my/my_str_to_word_array
** File description:
** hello world?
*/

#include <stdlib.h>
#include "../include/my.h"

static char *stwa_string(char *str, int *co, char const lim, char const *str2)
{
    int j = 0;
    int siz = 0;

    for (siz = 0; str2[siz + *co] != lim && str2[siz + *co] != '\0'; siz++);
    str = malloc(sizeof(char) * (siz + 1));
    if (str == NULL)
        return (NULL);
    for (j = 0; j != siz; j++)
        str[j] = str2[j + *co];
    str[siz] = '\0';
    *co += (siz + 1);
    return (str);
}

char **my_spliter(char *str, char const lim)
{
    int nb_word = 0;
    int co = 0;
    char **tab;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == lim)
            nb_word++;
    nb_word++;
    tab = malloc(sizeof(char*) * (nb_word + 1));
    if (tab == NULL)
        return (NULL);
    tab[nb_word] = NULL;
    for (int i = 0; i != nb_word; i++) {
        tab[i] = stwa_string(tab[i], &co, lim, str);
        if (tab[i] == NULL)
            return (NULL);
    }
    free(str);
    return (tab);
}