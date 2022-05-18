/*
** EPITECH PROJECT, 2021
** lib/my/my_str_to_word_array
** File description:
** hello world?
*/

#include <stdlib.h>
#include "../include/my.h"

static int count_word2(char *str, char split)
{
    int nb = 1;
    int i = 0;

    for (; str[i]; i++)
        if (str[i] == split || str[i] == '\t')
            nb++;
    return (nb);
}

static int word_len2(char const *str, char split)
{
    int len = 0;
    int i = 0;

    for (; str[i] == split || str[i] == '\t'; i++);
    for (; str[i] != split && str[i] != '\0' && str[i] != '\t'; i++, len++);

    return (len);
}

static char *fill_tab2(char *str, char *tab, char split)
{
    int i = 0;
    int j = 0;

    for (; str[i] == split || str[i] == '\t'; i++);
    for (; str[i] != split && str[i] != '\0' && str[i] != '\t'; i++, j++)
        tab[j] = str[i];
    tab[j] = '\0';

    return (tab);
}

static int count_len2(char const *str, char split)
{
    int i = 0;

    for (; str[i] == split || str[i] == '\t'; i++);
    for (; str[i] != split && str[i] != '\0' && str[i] != '\t'; i++);

    return (i);
}

char **my_spliter2(char *str, char const split)
{
    if (str == NULL)
        return NULL;
    int nb_word = count_word2(str, split);
    if (nb_word == 1)
        return (NULL);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;

    if (result == NULL)
        return (NULL);
    for (; i < nb_word; i++) {
        result[i] = malloc(sizeof(char) * (word_len2(str, split) + 1));
        result[i] = fill_tab2(str, result[i], split);
        str = str + count_len2(str, split);
    }
    result[i] = NULL;
    return (result);
}
