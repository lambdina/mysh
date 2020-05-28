/*
** EPITECH PROJECT, 2020
** builtin_which
** File description:
** built-in which main function
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "exec.h"
#include "env_handling.h"

int check_bltn_which(char **input)
{
    if (my_tablen((char const **)input) == 1) {
        error_msg("which", TOOFEW_ARGS);
        return 1;
    }
    return 0;
}

int built_in_which(char **input, UNUSED int r_value)
{
    char *path = NULL;
    bool not_found = false;

    if (check_bltn_which(input))
        return 1;
    for (int i = 1; input[i] != NULL; i++) {
        if (get_builtin(input[i])) {
            dprintf(1, "%s: shell built-in command.\n", input[i]);
            continue;
        }
        path = get_exec_input(input[i]);
        if (path != NULL) {
            dprintf(1, "%s\n", path);
            free(path);
        } else {
            error_msg(input[i], CMD_NOT_FOUND);
            not_found = true;
        }
    }
    return (not_found == true ? 1 : 0);
}
