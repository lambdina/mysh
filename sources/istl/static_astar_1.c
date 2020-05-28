/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_astar.h"
#include "istl/shared_ptr.h"
#include "istl/weak_ptr.h"

pnode_t *pnode_copy_unexplored(pnode_t *node, uint_t idx)
{
    pnode_t *lock = NULL;
    pnode_t *ret = NULL;

    if (node == NULL || node->near == NULL || idx >= node->namount)
        return (NULL);
    lock = wptr_lock(node->near[idx].dest);
    if (lock == NULL)
        return (NULL);
    if (lock == NULL || (node->from != NULL && lock->id == node->from->id)) {
        spdestroy(lock);
        return (NULL);
    }
    ret = pnode_copy(lock);
    spdestroy(lock);
    return (ret);
}
