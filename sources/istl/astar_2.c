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

#include "static_astar_2.c"

int pnode_set_final(pnode_t *node, bool_t val)
{
    if (node == NULL)
        return (-1);
    node->goal = val;
    return (0);
}

int pnode_link(pnode_t *lhs, pnode_t * rhs, int dist)
{
    bridge_t link;
    bridge_t *near = NULL;

    if (lhs == NULL || rhs == NULL)
        return (-1);
    lhs->namount += 1;
    near = malloc(sizeof(bridge_t) * lhs->namount);
    link.score = dist;
    link.dest = make_weak(rhs);
    near[0] = link;
    for (uint_t i = 1; i < lhs->namount; i++)
        near[i] = lhs->near[i - 1];
    free(lhs->near);
    lhs->near = near;
    return (0);
}

int pnode_detach(pnode_t *node)
{
    wptr_t *wp = NULL;

    if (node == NULL)
        return (-1);
    if (node->near == NULL)
        return (0);
    for (uint_t i = 0; i < node->namount; i++) {
        wp = node->near[i].dest;
        sdel(&wp);
    }
    free(node->near);
    node->near = NULL;
    node->namount = 0;
    return (0);
}

void pnode_backtrace(pnode_t *node, list_t *nodes)
{
    if (node == NULL)
        return;
    if (nodes != NULL) {
        list_push_front(nodes, node);
        if (node->from != NULL)
            pnode_backtrace(node->from, nodes);
    }
}

list_t *astar_navigate(pnode_t *startpoint)
{
    list_t *f = NULL;

    if (startpoint == NULL)
        return (NULL);
    f = list_create(MB_SPTR);
    if (pnode_advance(startpoint, f) < 1)
        return (NULL);
    while (list_len(f) != 0)
        if (astar_step(f) == TRUE)
            return (f);
    list_free(&f);
    return (NULL);
}
