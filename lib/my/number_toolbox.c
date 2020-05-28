/*
** EPITECH PROJECT, 2019
** number_toolbox.c
** File description:
** everything i may need to display a number
*/

#include "lib.h"

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0) {
        if (nb >= 10) {
            my_putnbr(nb / 10);
            my_putchar(nb % 10 + 48);
        }
        else my_putchar(nb + 48);
    }
}

void my_putnbr_base(int nb, const char *base)
{
    char *converted_nb = my_getnbr_base(nb, base);

    my_putstr(converted_nb);
    free_if_not_null(converted_nb);
}
