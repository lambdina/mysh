/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <stdio.h>
#include "istl/weak_ptr.h"
#include "istl/private/p_astar.h"

bool_t pnode_further_then(iterator_t lhs_it, iterator_t rhs_it)
{
    pnode_t *lhs = it_data(lhs_it);
    pnode_t *rhs = it_data(rhs_it);

    if (lhs->score > rhs->score)
        return (TRUE);
    return (FALSE);
}

void pnode_print(void *node_p)
{
    pnode_t *node = node_p;

    if (node == NULL)
        return;
}

bool_t pnode_comes_from(pnode_t const *lhs, pnode_t const *rhs)
{
    pnode_t *from = NULL;
    bool_t ret = FALSE;

    if (lhs == NULL || rhs == NULL)
        return (FALSE);
    if (!wptr_valid(lhs->from))
        return (FALSE);
    from = wptr_lock(lhs->from);
    ret = (lhs == rhs) ? TRUE : ret;
    ret = (from->id == rhs->id) ? TRUE : ret;
    sdel(&from);
    return (ret);
}

bridge_t *bridge_cpy_array(bridge_t const *bridges, uint_t len)
{
    bridge_t *copy = NULL;

    if (bridges == NULL)
        return (NULL);
    copy = malloc(sizeof(bridge_t) * len);
    for (uint_t i = 0; i < len; i++) {
        copy[i] = bridges[i];
        copy[i].dest = wpcopy(bridges[i].dest);
    }
    return (copy);
}
