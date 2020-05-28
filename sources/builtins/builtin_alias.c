/*
** EPITECH PROJECT, 2020
** builtins.h
** File description:
** builtins module header
*/

#include "42sh.h"
#include "lib.h"
#include "builtins.h"
#include "exec.h"
#include "istl/utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include "istl/vector.h"
#include "input_module.h"
#include "env_handling.h"

int built_in_alias(char **input, UNUSED int rvalue)
{
    int ipt_len = my_tablen((char const **)input);

    if (ipt_len == 3)
        return update_alias(input, true), 0;
    else if (ipt_len == 2)
        return display_alias(input[1]);
    return 0;
}

vector_t *get_alias_vector(void)
{
    static vector_t *vector = NULL;
    static bool_t is_init = FALSE;

    if (!is_init) {
        vector = vector_create((mdata_t){NULL, NULL, sizeof(alias_t)});
        is_init = true;
    }

    return (vector);
}

uint_t get_alias_index(vector_t *aliases, char const *alias)
{
    alias_t *ptr = NULL;

    for (uint_t result = 0; result < vector_len(aliases); result++) {
        ptr = vector_get(aliases, result);
        if (my_strcmp(ptr->alias, alias) == 0)
            return result;
    }
    return vector_len(aliases) + 1;
}

int display_alias(char *alias)
{
    alias_t alias_struct = {.command = NULL, .alias = my_strdup(alias)};
    vector_t *alias_list = get_alias_vector();
    uint_t idx = get_alias_index(alias_list, alias_struct.alias);
    alias_t *ptr = NULL;

    if (idx > vector_len(alias_list) + 1)
        return 0;
    ptr = vector_get(alias_list, idx);
    if (ptr == NULL) {
        return 0;
    }
    my_putstr(ptr->command);
    my_putstr("\n");
    return 0;
}

void update_alias(char **input, bool add_alias)
{
    alias_t alias = {
        .command = add_alias ? my_strdup(input[2]) : NULL,
        .alias = my_strdup(input[1])
    };
    vector_t *aliases = get_alias_vector();
    uint_t alias_pos = get_alias_index(aliases, alias.alias);

    if (add_alias == false) {
        if (alias_pos == vector_len(aliases) + 1)
            return;
        free(vector_pull(aliases, alias_pos));
        vector_narrow(aliases);
    } else {
        if (alias_pos < vector_len(aliases) + 1)
            vector_set(aliases, alias_pos, &alias);
        else vector_push(aliases, &alias);
    }
}
