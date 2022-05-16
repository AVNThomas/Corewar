/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** list_champ
*/

#include "../include/corewar.h"

champions_t *init_node(champions_t *champ)
{
    champ->comment = malloc(sizeof(char) * (COMMENT_LENGTH + 1));
    champ->name = malloc(sizeof(char) * (PROG_NAME_LENGTH + 1));
    champ->number = 0;
    champ->ptr = NULL;
    champ->next = NULL;
    return (champ);
}

champions_t *add_value(champions_t *list, vm_header_t *header, args_t *arg)
{
    list->ptr = fopen(arg->name, "rb");
    list->number = arg->number;
    list->next = NULL;
    list->name = my_strcpy(list->name, header->name);
    list->comment = my_strcpy(list->comment, header->comment);
    return (list);
}

champions_t *add_champ(champions_t *list, vm_header_t *header, args_t *arg)
{
    champions_t *new = malloc(sizeof(champions_t));
    champions_t *tmp = list;

    new = init_node(new);
    new = add_value(new, header, arg);
    if (list == NULL)
        return (new);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

void print_champ(champions_t *champ)
{
    champions_t *tmp = champ;

    while (tmp != NULL) {
        my_printf("Name = %s : ", tmp->name);
        my_printf("Number = %d : ", tmp->number);
        my_printf("Comment = %s\n", tmp->comment);
        tmp = tmp->next;
    }
}

void free_champ(champions_t *champ)
{
    champions_t *tmp = champ;

    while (tmp != NULL) {
        free(tmp->name);
        free(tmp->comment);
        fclose(tmp->ptr);
        tmp = tmp->next;
    }
    free(champ);
}
