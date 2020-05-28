/*
** EPITECH PROJECT, 2020
** builtin_cd2.c
** File description:
** changedir miscellaneous functions
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "env_handling.h"
#include "exec.h"

char **update_pwd_values(char **env, char *pwd, char *old_pwd)
{
    char *arg_pwd = my_strcat("PWD=", pwd);
    char *arg_oldpwd = my_strcat("OLDPWD=", old_pwd);

    env = set_to_env(env, arg_pwd);
    env = set_to_env(env, arg_oldpwd);
    free(arg_pwd);
    free(old_pwd);
    return (env);
}

char *get_path(char *input)
{
    char *cwd = malloc(sizeof(char) * 75);

    cwd = getcwd(cwd, 75);
    cwd = my_strcat(cwd, "/");
    input = my_strcat(cwd, input);
    free(cwd);
    return (input);
}

char **update_cd_argument(char **input)
{
    char *home = getline_from_env(environ, "HOME=");
    char *cwd = NULL;

    if (my_tablen((char const **)input) == 1)
        return (append_str(input, home));
    else if (my_tablen((char const **)input) == 2
    && my_strcmp(input[1], "~") == 0)
        input[1] = my_strdup(home);
    if (my_strcmp(input[1], "-") == 0) {
        cwd = malloc(sizeof(char) * 100);
        cwd = getcwd(cwd, 100);
        input[1] = getline_from_env(environ, "OLDPWD=");
        if (my_strcmp(input[1], cwd) == 0) {
            free(cwd);
            write(2, ": No such file or directory.\n", 29);
            return (NULL);
        }
    }
    free(cwd);
    return (input);
}
