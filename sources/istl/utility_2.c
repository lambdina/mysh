/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include <stdlib.h>

map_t *global_manager(int sig)
{
    static map_t *storage = 0;

    if (sig == 1) {
        map_free(&storage);
        return (0);
    } else if (sig == 2) {
        return (storage);
    } else {
        storage = (storage == 0) ? map_create(10, MB_UTYPE) : storage;
    }
    return (storage);
}

void utility_reset(void)
{
    global_manager(1);
}

void utility_set_var(char const *str, utype_t var)
{
    map_t *global = (str == 0) ? 0 : global_manager(0);
    utype_t *pvar = 0;

    if (str == 0 || global == 0)
        return;
    pvar = map_pull(global, hash_str(str));
    if (pvar != 0)
        free(pvar);
    map_insert(global, hash_str(str), &var);
}

void *utility_get_var(char const *str)
{
    map_t *global = global_manager(0);

    if (str == 0 || global == 0)
        return (0);
    return (map_get(global, hash_str(str)));
}

bool_t utility_sready(void)
{
    if (global_manager(2) == 0)
        return (FALSE);
    return (TRUE);
}
