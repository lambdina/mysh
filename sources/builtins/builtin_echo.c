/*
** EPITECH PROJECT, 2020
** builtin_echo.c
** File description:
** handles echo builtin
*/

#include "lib.h"
#include "42sh.h"
#include "builtins.h"

int built_in_echo(char **input, UNUSED int rvalue)
{
    int nb_args = my_tablen((char const **)input);

    for (int i = 1; i < nb_args; i++) {
        my_putstr(input[i]);
        if (input[i + 1] != NULL)
            my_putchar(' ');
    }
    my_putchar('\n');
    return 0;
}
