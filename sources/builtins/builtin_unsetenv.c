/*
** EPITECH PROJECT, 2020
** built_in_unsetenv
** File description:
** handles unsetenv built_in.
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "env_handling.h"
#include "exec.h"

int built_in_unsetenv(char **input, UNUSED int return_value)
{
    int pos_in_env = -1;

    if (unsetenv_check_input(input) == -1)
        return (1);
    input[1] = my_strcat(input[1], "=");
    pos_in_env = find_in_env(environ, input[1]);
    if (pos_in_env == -1) {
        return (0);
    }
    environ = reset_from_position(pos_in_env, environ);
    return (0);
}

char **reset_from_position(int position, char **env)
{
    int i = position;

    for ( ; env[i + 1] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    free(env[i + 1]);
    return (env);
}

int unsetenv_check_input(char **input)
{
    if (my_tablen((char const **)input) == 1)
        return error_msg("unsetenv", TOOFEW_ARGS) - 2;
    return (0);
}
