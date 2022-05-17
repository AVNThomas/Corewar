/*
** EPITECH PROJECT, 2022
** my_essential
** File description:
** flags_two
*/

#include "../../include/printf.h"

void percent_f(va_list arglist)
{
    my_putnbr_float(va_arg(arglist, double));
}

void percent_e(va_list arglist)
{
    my_puterror(va_arg(arglist, char *));
}

void percent_p(va_list arglist)
{
    int i = 0;
    int rest = 0;
    uintptr_t nb = va_arg(arglist, uintptr_t);
    char *buffer = malloc(sizeof(char) * 11);

    for (; nb != 0; i++) {
        rest = nb % 16;
        if (rest >= 10) {
            buffer[i] = rest - 10 + 'a';
        } else {
            buffer[i] = rest + '0';
        }
        nb /= 16;
    }
    buffer[i - 1] = '\0';
    my_revstr(buffer);
    my_putstr("0x");
    my_putstr(buffer);
    free(buffer);
}

void percent_b(va_list arglist)
{
    int i = 0;
    int nb = va_arg(arglist, int);
    char *buffer = malloc(sizeof(char) * nb);

    for (; nb != 0; i++) {
        buffer[i] = (nb % 2) + '0';
        nb /= 2;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    my_putstr(buffer);
    free(buffer);
}

void percent_x(va_list arglist)
{
    int i = 0;
    int rest = 0;
    int nb = va_arg(arglist, int);
    char *buffer = malloc(sizeof(char) * (nb + 1));

    for (; nb != 0; i++) {
        rest = nb % 16;
        if (rest >= 10) {
            buffer[i] = rest - 10 + 'a';
        } else {
            buffer[i] = rest + '0';
        }
        nb /= 16;
    }
    buffer[i] = '\0';
    my_revstr(buffer);
    my_putstr(buffer);
    free(buffer);
}
