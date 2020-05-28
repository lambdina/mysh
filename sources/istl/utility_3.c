/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include "istl/string.h"
#include <stdlib.h>

bool_t fnode_null(fnode_t const *node)
{
    bool_t res = TRUE;
    const fnode_t *const ref = &FNODE_NULL;

    if (node == NULL)
        return (FALSE);
    res = (node->cset != ref->cset) ? FALSE : res;
    res = (node->ps != ref->ps) ? FALSE : res;
    res = (node->ns != ref->ns) ? FALSE : res;
    res = (node->fs != ref->fs) ? FALSE : res;
    return (res);
}

bool_t regex_extract(cchar_t str, fnode_t const *const pattern,
        map_t *grp, int *state)
{
    fnode_t const *node_p = NULL;
    bool_t final = FALSE;

    if (str == NULL || pattern == NULL || state == NULL)
        return (0);
    map_drop(grp);
    (*state) = 0;
    for (uint_t i = 0; str[i] != 0; i++) {
        final = FALSE;
        node_p = regex_forward(str[i], pattern, state);
        if (node_p != NULL) {
            final = node_p->fs;
            regex_extract_char(str[i], node_p, grp);
        }
    }
    if (final != TRUE)
        map_drop(grp);
    return (final);
}
