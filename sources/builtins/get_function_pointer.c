/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** get_function_pointer
*/

#include "builtin_fptr.h"

builtin_t get_builtin(char *input)
{
    if (input == NULL || input[0] == 0)
        return (NULL);
    for (int i = 0; BUILTINS[i].ptr != NULL; i++)
        if (my_strcmp(BUILTINS[i].command, input) == 0)
            return (BUILTINS[i].ptr);
    return (NULL);
}