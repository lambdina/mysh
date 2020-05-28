/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <wordexp.h>
#include "istl/utility.h"
#include "istl/vector.h"
#include "istl/string.h"
#include "input_module.h"
#include "builtins.h"

void backup_io(int fd[2])
{
    if (fd == NULL)
        return;
    fd[0] = dup(STDIN_FILENO);
    fd[1] = dup(STDOUT_FILENO);
}

void reset_io(int fd[2])
{
    if (fd == NULL)
        return;
    close(STDIN_FILENO);
    dup2(fd[0], STDIN_FILENO);
    close(STDOUT_FILENO);
    dup2(fd[1], STDOUT_FILENO);
}

void from_wordexp(wordexp_t we, vector_t *exp)
{
    string_t *str = NULL;

    if (exp == NULL)
        return;
    for (size_t j = 0; j < we.we_wordc; j++) {
        str = str_create(we.we_wordv[j]);
        if (str != NULL && str_len(str) > 0)
            vector_push(exp, str);
    }
}

vector_t *expand_aliases(vector_t *args)
{
    vector_t *aliases = get_alias_vector();
    list_t *nargs = (args == NULL) ? NULL : list_create(MB_STR);
    string_t *str = {NULL};
    uint_t idx;
    alias_t *alias = NULL;

    if (args == NULL)
        return NULL;
    for (uint_t i = 0; i < vector_len(args); i++) {
        str = vector_get(args, i);
        idx = get_alias_index(aliases, str_cstr(str));
        if (idx > vector_len(aliases) || i != 0) {
            list_push_back(nargs, str);
        } else {
            alias = vector_get(aliases, idx);
            str = str_create(alias->command);
            list_merge(nargs, str_split(str, ' '));
        }
    }
    return (vector_from_list(nargs));
}
