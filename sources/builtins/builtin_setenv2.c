/*
** EPITECH PROJECT, 2020
** builtin_setenv.c
** File description:
** built-in setenv misc function
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "env_handling.h"

bool check_if_alphanum(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z'))
        return (true);
    return (false);
}