/*
** EPITECH PROJECT, 2020
** builtins.h
** File description:
** builtins module header
*/

#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include "builtins.h"
#include "42sh.h"
#include "lib.h"

#ifndef FPTR_BUILTINS_H
#define FPTR_BUILTINS_H

typedef struct bltin_fptr_s
{
    char *command;
    builtin_t ptr;
} bltin_fptr_t;

const bltin_fptr_t BUILTINS[] = {
    {"cd", &built_in_cd},
    {"env", &built_in_env},
    {"exit", &built_in_exit},
    {"echo", &built_in_echo},
    {"setenv", &built_in_setenv},
    {"unsetenv", &built_in_unsetenv},
    {"new_prompt", &built_in_prompt},
    {"where", &built_in_where},
    {"which", &built_in_which},
    {"source", &built_in_source},
    {"alias", &built_in_alias},
    {NULL, NULL}
};

// get_function_pointer.c
builtin_t get_builtin(char *input);

#endif
