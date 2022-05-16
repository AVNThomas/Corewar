/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_name
*/

#include "../include/asm.h"
#include <stdlib.h>

static int check_asm_line(char *line, asm_list_t *list)
{
    int size_comment = my_strlen(COMMENT_CMD_STRING);
    int size_name = my_strlen(NAME_CMD_STRING);

    if (my_char_is_alnum(line[0]))
        line++;
    if (my_strncmp(COMMENT_CMD_STRING, line, size_comment) == 0 ||
        my_strncmp(NAME_CMD_STRING, line, size_name) == 0)
        return (0);
    list = add_nod_list(list, line);
    if (list == NULL)
        return (EXIT_ERR);
    return (1);
}

asm_list_t *compile_core(asm_list_t *list, char *asm_buff)
{
    char **tab = my_spliter(asm_buff, '\n');

    for (int i = 0; tab[i] != NULL; i++)
        if (check_asm_line(tab[i], list) == EXIT_ERR) {
            free_linked_list(list);
            free_double_array(tab);
            return (NULL);
        }
    free_double_array(tab);
    return (list);
}
