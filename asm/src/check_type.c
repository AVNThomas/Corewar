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

static int check_type(char *word)
{
    if (check_register(word))
        return (1);
    else if (word[0] == '%')
        return (2);
    else
        return (3);
}

static int check_type_elem(asm_list_t *list, char **tab, int i)
{
    int error = 0;

    printf("coucou type elem\n");
    printf("%d \n", list->asm_line.type[i]);
    if (list->asm_line.type[i] == 4 && check_type(tab[i + list->pos + 1]) != 3)
        error++;
    if (list->asm_line.type[i] == 2 && check_type(tab[i + list->pos + 1]) != 2)
        error++;
    if (list->asm_line.type[i] == 1 && check_type(tab[i + list->pos + 1]) != 1)
        error++;
    if (list->asm_line.type[i] == 6 && check_type(tab[i + list->pos + 1]) == 1)
        error++;
    if (list->asm_line.type[i] == 5 && check_type(tab[i + list->pos + 1]) == 2)
        error++;
    if (list->asm_line.type[i] == 3 && check_type(tab[i + list->pos + 1]) == 3)
        error++;
    return (error);
}

static int check_elem(asm_list_t *list)
{
    char **tab = my_spliter(list->line, ' ');
    int error = 0;
    int size = 0;

    printf("coucou check elem\n");
    for (; tab[size] != NULL; size++);
    if (size != list->asm_line.nbr_args + list->pos + 1)
        return (1);
    for (int i = 0; i != list->asm_line.nbr_args; i++) {
        error = check_type_elem(list, tab, i);
    }
    free_double_array(tab);
    return (error);
}

int check_list_elem(asm_list_t *list)
{
    asm_list_t *backup = list;

    printf("check list\n%p", list);

    for (; list == NULL; list = list->next) {
        printf("%s\n", list->line);
        if (check_elem(list) != 0) {
            list = backup;
            printf("error lol\n");
            return (EXIT_ERR);
        }
    }
    printf("C OK lol\n");
    list = backup;
    return (EXIT_OK);
}
