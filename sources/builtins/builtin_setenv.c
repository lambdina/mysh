/*
** EPITECH PROJECT, 2020
** builtin_setenv.c
** File description:
** built-in setenv main function
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "env_handling.h"
#include "exec.h"

int built_in_setenv(char **input, int return_value)
{
    char *value = NULL;

    if (setenv_check_input(input, return_value) == -1)
        return (1);
    if (input[1][my_strlen(input[1]) - 1] != '=')
        value = my_strcat(input[1], "=");
    else value = my_strdup(input[1]);
    value = my_strcat(value, input[2]);
    environ = set_to_env(environ, value);
    return (0);
}

static char *send_until(char *s, char stop_at)
{
    if (s == NULL || s[0] == 0)
        return (NULL);
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == stop_at) {
            s[i] = '\0';
        }
    return (s);
}

char **set_to_env(char **env, char *value)
{
    char *temp = send_until(my_strdup(value), '=');
    int pos_in_env = find_in_env(env, my_strcat(temp, "="));

    free_if_not_null(temp);
    if (pos_in_env == -1)
        return (add_to_env(env, value));
    else env[pos_in_env] = my_strdup(value);
    return (env);
}

static bool check_if_alphanumeric(char *value)
{
    for (int i = 0; value[i] != '\0'; i++) {
        if (!check_if_alphanum(value[i])) {
            error_msg("setenv", ALPHANUM);
            return (false);
        }
    }
    return (true);
}

int setenv_check_input(char **input, int return_value)
{
    char **new_input = tabgen("env", '\n');

    if (my_tablen((char const **)input) == 1) {
        built_in_env(new_input, return_value);
        free_tab((void **)new_input);
        return (-1);
    }
    else if (my_tablen((char const **)input) > 3) {
        error_msg("setenv", TOOMANY_ARGS);
        free_tab((void **)new_input);
        return (-1);
    }
    return (!check_if_alphanumeric(input[1]) ? -1 : 0);
}
