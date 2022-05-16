/*
** EPITECH PROJECT, 2022
** B-CPE-201-NCY-2-1-corewar-antoine.khalidy
** File description:
** converter
*/

#include "../include/corewar.h"

static int my_compute_power_it(int nb, int p)
{
    int i = 0;
    int result = 1;

    for (; i < p; i++)
        result *= nb;
    return (result);
}

int hexa_to_decimal2(int hexa)
{
    int decimal = 0;
    int i = 0;

    while (hexa != 0) {
        decimal += (hexa % 10) * my_compute_power_it(16, i);
        hexa /= 10;
        i++;
    }
    return (decimal);
}

int hexa_to_decimal(char *hexa)
{
    int decimal = 0;

    for (int i = 0; hexa[i] != '\0'; i++) {
        if (hexa[i] >= '0' && hexa[i] <= '9')
            decimal = decimal * 16 + (hexa[i] - '0');
        else if (hexa[i] >= 'a' && hexa[i] <= 'f')
            decimal = decimal * 16 + (hexa[i] - 'a' + 10);
        else if (hexa[i] >= 'A' && hexa[i] <= 'F')
            decimal = decimal * 16 + (hexa[i] - 'A' + 10);
    }
    return (decimal);
}

int decimal_to_binary(int decimal)
{
    int i = 0;
    int binary = 0;
    char *buffer = malloc(sizeof(char) * (decimal + 1));

    for (; decimal != 0; i++) {
        buffer[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    binary = my_atoi(buffer);
    free(buffer);
    return (binary);
}
