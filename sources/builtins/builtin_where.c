/*
** EPITECH PROJECT, 2020
** built-in where
** File description:
** buils_in where main function
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "exec.h"
#include "env_handling.h"

int check_bltn_where(char **input)
{
    if (my_tablen((char const **)input) == 1) {
        error_msg("where", TOOFEW_ARGS);
        return 1;
    }
    return 0;
}

int built_in_where(char **input, UNUSED int r_value)
{
    char **path = NULL;

    if (check_bltn_where(input))
        return 1;
    for (int i = 1; input[i] != NULL; i++) {
        if (get_builtin(input[i]))
            dprintf(1, "%s is a shell built-in\n", input[i]);
        path = get_all_exec_ipt(input[i], get_exec_paths(environ));
        for (int j = 0; path != NULL && path[j] != NULL; j++)
            dprintf(1, "%s\n", path[j]);
        if (path != NULL)
            free_tab((void **)path);
    }
    return 0;
}
