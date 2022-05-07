/*
** EPITECH PROJECT, 2022
** project_name
** File description:
** write_header
*/

#include "../include/asm.h"

int magic_header(int *header)
{
    int ret_stat = EXIT_OK;
    int magic = COREWAR_EXEC_MAGIC;

    magic = __builtin_bswap32(magic);
    *header = magic;
    return (ret_stat);
}

static int check_if_valid(char *elem, char *valid_char)
{
    for (int i = 0; valid_char[i] != '\0'; i++)
        for (int j = 0; elem[j] != '\0'; j++)
            if (elem[j] != valid_char[i])
                return(EXIT_ERR);
    return (EXIT_OK);
}

static char *find_line(char *header, char **tab, char *search)
{
    for (int i = 0; tab[i] != NULL; i++) 
        if (my_strncmp(search, tab[i],
        my_strlen(search)) == 0 && check_if_valid(tab[i], LABEL_CHARS)) {
            header = my_strcpy(header, tab[i]);
            return (header);
        }
    return (NULL);
}

int name_header(char **asm_buff, char *header)
{
    char *tmp = find_line(header, asm_buff, NAME_CMD_STRING);
    int last_quote = 0;
    if (tmp == NULL)
        return (EXIT_ERR);
    for (int i = my_strlen(NAME_CMD_STRING); i > -2; i--, tmp++);
    for (; tmp[last_quote] != '"'; last_quote++);
    tmp[last_quote] = '\0';
    my_printf("%s\n", tmp);
    header = my_strcpy(header, tmp);
    return (EXIT_OK);
}

int comment_header(char **asm_buff, char *header)
{
    asm_buff = asm_buff;
    header = header;
    return (EXIT_OK);
}

header_t *generate_header(header_t *header, char *asm_buff)
{
    char **tab = my_spliter(asm_buff, '\n');

    if (tab == NULL)
        return (NULL);
    if (magic_header(&(*header).magic) == EXIT_ERR || 
    name_header(tab, header->prog_name) == EXIT_ERR) {
        free_double_array(tab);
        return (NULL);
    }
    printf("header magic %x\n", header->magic);
    my_printf("header name %s\n", header->prog_name);
    my_printf("header size %d\n", header->prog_size);
    my_printf("header comment %s\n", header->comment);
    free_double_array(tab);
    return (header);
}