/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** open_file
*/

#include "../include/my.h"

char *getline_file(FILE *file)
{
    char *buffer = malloc(sizeof(char));
    char *line = NULL;
    long unsigned int size = 0;
    ssize_t byte = 0;

    if (buffer == NULL)
        return (NULL);
    if (file == NULL) {
        free(buffer);
        return (NULL);
    }
    buffer = my_memset(buffer, 0, sizeof(char));
    byte = getline(&line, &size, file);
    while (byte >= 0) {
        buffer = my_strcat_malloc(buffer, line);
        byte = getline(&line, &size, file);
    }
    free(line);
    return (buffer);
}

char *stat_file(char *filepath)
{
    struct stat statbuff;
    int file_d = 0;
    char *buffer = NULL;

    stat(filepath, &statbuff);
    file_d = open(filepath, O_RDONLY);
    if (file_d == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * statbuff.st_size + 1);
    if (read(file_d, buffer, statbuff.st_size) <= 0)
        return (NULL);
    close(file_d);
    buffer[statbuff.st_size] = 0;
    return (buffer);
}

int write_in_file(char const *filename, char const *data)
{
    int file_d = 0;

    file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file_d < 0)
        return (1);
    write(file_d, data, my_strlen(data));
    close(file_d);
    return (0);
}

int d2_arr_size(char **tab)
{
    int i = 0;
    if (tab == NULL)
        return (0);
    for (; tab[i] != NULL; i++);
    return (i);
}
