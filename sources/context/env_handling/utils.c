/*
** EPITECH PROJECT, 2020
** utils.c
** File description:
** utils regarding env handling
*/

#include "42sh.h"
#include "env_handling.h"
#include <string.h>
#include "builtins.h"
#include "lib.h"

char **add_to_env(char **env, char *to_add)
{
    static bool is_first_time = true;
    char **result = NULL;
    int size = my_tablen((char const **)env);
    int i = 0;

    if (to_add == NULL || to_add[0] == 0)
        return env;
    result = malloc(sizeof(char *) * (size + 2));
    if (!result)
        return (free_tab((void **)env), free(to_add), NULL);
    for (; env[i] != NULL; i++)
        result[i] = my_strdup(env[i]);
    result[i] = my_strdup(to_add);
    result[i + 1] = NULL;
    if (is_first_time == false) {
        free_tab((void **)env);
    } else is_first_time = false;
    return (result);
}

int find_in_env(char **tab, char *to_find)
{
    if (tab == NULL || tab[0] == NULL || to_find == NULL)
        return -1;
    for (int i = 0; tab[i] != NULL; i++)
        if (my_strncmp(tab[i], to_find, my_strlen(to_find) - 1) == 0)
            return i;
    return -1;
}

char *getline_from_env(char **env, char *to_find)
{
    char *result = NULL;
    int to_find_len = my_strlen(to_find);

    if (to_find == NULL || to_find[0] == 0)
        return (NULL);
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], to_find, to_find_len - 1) == 0) {
            result = my_strdup(env[i]);
            result = my_strdup(&result[to_find_len]);
            return result;
        }
    }
    return NULL;
}