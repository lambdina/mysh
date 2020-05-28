/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <stdio.h>
#include "istl/private/p_astar.h"

bool_t pnode_locked(pnode_t const *node)
{
    return (node->locked);
}

bool_t pnode_toggle(pnode_t *node)
{
    node->locked = (node->locked == TRUE) ? FALSE : TRUE;
    return (node->locked);
}
