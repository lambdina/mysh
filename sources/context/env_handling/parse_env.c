/*
** EPITECH PROJECT, 2019
** get_env.c
** File description:
** loads env into shell_env_t struct - return 84 if error / 0 if success
*/

#include "istl/common_types.h"
#include "42sh.h"
#include "lib.h"
#include "env_handling.h"
#include <string.h>

char **get_exec_paths(char **env)
{
    if (env == NULL || env[0] == NULL || env[0][0] == '\0')
        return NULL;
    return tabgen(getline_from_env(env, "PATH="), ':');
}

char *load_path(char *path, char *input)
{
    char *result = NULL;
    char *slash = my_strdup("/");
    int size = my_strlen(path) + my_strlen(slash) + my_strlen(input);
    int i = 0;

    if (path == (void *)0 || input == (void *)0) {
        if (input == (void *)0)
            return (path);
        else if (path == (void *)0)
            return (input);
    }
    result = malloc(sizeof(char) * (size + 1));
    for (i = 0; i < my_strlen(path); i++)
        result[i] = path[i];
    result[my_strlen(path)] = 0;
    strcat(result, slash);
    strcat(result, input);
    return result;
}
