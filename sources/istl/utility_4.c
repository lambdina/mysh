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

void regex_extract_char(
        char chr,
        fnode_t const *node_p,
        map_t *grp)
{
    string_t *str_p = NULL;
    string_t *tmp = NULL;
    int i = 0;
    bool_t set = FALSE;

    if (grp == NULL)
        return;
    do {
        str_p = (grp == NULL) ? NULL : map_pull(grp, i);
        str_p = (str_p == NULL) ? str_create("") : str_p;
        tmp = str_addch(str_p, chr);
        str_free(&str_p);
        map_insert(grp, i, tmp);
        str_free(&tmp);
        if (!set) {
            set = TRUE;
            i = node_p->gwl;
        } else
            i += 1;
    } while (i < node_p->gwr);
}

bool_t regex_wild(fnode_t const *node)
{
    if (node == NULL)
        return (FALSE);
    if (node->cset == RC_WILD)
        return (TRUE);
    return (FALSE);
}
