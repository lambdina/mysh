/*
** EPITECH PROJECT, 2020
** write_toolbox.c
** File description:
** write toolbox
*/

#include "lib.h"
#include <unistd.h>

void my_putchar(char c)
{
    if (!write(1, &c, 1))
        return;
}

void my_putstr(char const *s)
{
    if (s == NULL || s[0] == '\0')
        return;
    else if (!write(1, s, my_strlen(s)))
        return;
}

void my_puterror(char const *s)
{
    if (s == NULL || s[0] == '\0')
        return;
    else if (!write(2, s, my_strlen(s)))
        return;
}

void display_tab(char const **tab)
{
    if (tab == NULL || tab[0] == NULL || tab[0][0] == '\0')
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
