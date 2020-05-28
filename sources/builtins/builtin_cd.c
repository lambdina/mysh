/*
** EPITECH PROJECT, 2020
** builtin_cd.c
** File description:
** handles cd built-in
*/

#include "lib.h"
#include "42sh.h"
#include "builtins.h"
#include "env_handling.h"
#include <stdio.h>
#include "exec.h"

int built_in_cd(char **input, UNUSED int return_value)
{
    input = cd_error_handling(input);
    if (input == NULL || input[0] == NULL || input[0][0] == 0)
        return (1);
    return (change_dir(input));
}

char **cd_error_handling(char **input)
{
    if (my_tablen((char const **)input) == 1 ||
    (my_tablen((char const **)input) == 2  &&
    (my_strcmp(input[1], "-") == 0 ||
    is_in_string(input[1], '~') != -1)))
        return (update_cd_argument(input));
    else if (my_tablen((char const **)input) != 2) {
        error_msg("cd", TOOMANY_ARGS);
        return (NULL);
    }
    return (input);
}

int change_dir(char **input)
{
    char *path = NULL;
    char *old_path = NULL;

    if (is_dir_accessible(input[1]) == false)
        return (error_msg(NULL, NO_SUCH_FILE));
    old_path = getline_from_env(environ, "PWD=");
    path = input[1][0] != '/' ? get_path(input[1]) : my_strdup(input[1]);
    chdir(path);
    environ = update_pwd_values(environ, path, old_path);
    free(path);
    return (0);
}

bool is_dir_accessible(char *input)
{
    struct stat st;
    char *pwd = NULL;
    char *input_cpy = my_strdup(input);

    if (input == NULL)
        return free(input_cpy), false;
    if (input[0] != '/') {
        pwd = getline_from_env(environ, "PWD=");
        pwd = append_char(pwd, '/');
        input = my_strcat(pwd, input);
        free(pwd);
    }
    if (stat(input, &st) != -1) {
        if (!is_directory(st, input_cpy))
            return (false);
        free(input_cpy);
        return (true);
    }
    error_msg(input_cpy, NO_SUCH_FILE);
    return free(input_cpy), false;
}

bool is_directory(struct stat st, char *input_cpy)
{
    if (!S_ISDIR(st.st_mode)) {
        error_msg(input_cpy, NOT_A_DIR);
        free(input_cpy);
        return (false);
    }
    return (true);
}
