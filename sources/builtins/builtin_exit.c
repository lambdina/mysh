/*
** EPITECH PROJECT, 2020
** builtin_exit.c
** File description:
** handles exit built_in
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"

int built_in_exit(char **input, int return_value)
{
    int value = my_tablen((char const **)input) > 1 ?
    my_getnbr(input[1]) : return_value;

    if (isatty(0))
        my_putstr("exit\n");
    free_tab((void **)input);
    free_tab((void **)environ);
    exit(value);
}
