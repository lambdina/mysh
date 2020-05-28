/*
** EPITECH PROJECT, 2020
** builtin_env.c
** File description:
** handles env built_in
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "exec.h"

int built_in_env(char **input, UNUSED int return_value)
{
    if (my_tablen((char const **)input) != 1)
        return error_msg("env", NOARGS_ACC);
    display_tab((char const **)environ);
    return (0);
}
