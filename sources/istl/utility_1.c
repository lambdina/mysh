/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_utility.h"
#include "istl/hash_table.h"
#include <stdlib.h>

#include "./regex_const.c"

const meta_bundle_t MB_UTYPE = {0, 0, sizeof(utype_t)};

uint_t expect_uint(uint_t val, uint_t lhs, uint_t rhs)
{
    val = val < lhs ? lhs : val;
    val = val > rhs ? rhs : val;
    return (val);
}

bool_t str_contains(cchar_t set, char c)
{
    if (set == NULL)
        return (FALSE);
    for (uint_t i = 0; set[i] != 0; i++) {
        if (set[i] == c)
            return (TRUE);
    }
    return (FALSE);
}

fnode_t const *regex_forward(char c, const fnode_t arr[], int *state_p)
{
    int nstate = -1;
    fnode_t const *node_p = NULL;

    if (state_p == NULL || arr == NULL)
        return (NULL);
    for (uint_t i = 0; !fnode_null(arr + i); i++) {
        if (arr[i].ps != *state_p)
            continue;
        if (str_contains(arr[i].cset, c) || regex_wild(arr + i)) {
            nstate = arr[i].ns;
            node_p = arr + i;
        }
    }
    *state_p = nstate;
    return (node_p);
}

bool_t str_uint(cchar_t str)
{
    int state = 0;
    fnode_t const *const pattern = REGEX_UINT;

    if (str == NULL)
        return (FALSE);
    for (uint_t i = 0; str[i] != 0; i++) {
        regex_forward(str[i], pattern, &state);
    }
    return ((state > 1 && state < 4) ? TRUE : FALSE);
}
