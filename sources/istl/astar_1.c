/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_astar.h"
#include "istl/weak_ptr.h"
#include "istl/shared_ptr.h"

#include "static_astar_1.c"

const mdata_t MB_PNODE = {
    .copy = pnode_copy,
    .destroy = pnode_destroy,
    .data_size = sizeof(pnode_t)
};

pnode_t *pnode_create(unsigned int id, int score)
{
    pnode_t *pnode = shared_ptr(MB_PNODE);

    pnode->id = id;
    pnode->from = NULL;
    pnode->score = score;
    pnode->cost = 0;
    pnode->goal = FALSE;
    pnode->near = NULL;
    pnode->namount = 0;
    return (pnode);
}

void *pnode_copy(void const *node_p)
{
    pnode_t *nnode = NULL;
    pnode_t const *node = node_p;

    if (node == NULL)
        return (NULL);
    nnode = shared_ptr(MB_PNODE);
    *nnode = *node;
    nnode->from = (node->from == NULL) ? NULL : spcopy(node->from);
    if (node->near != NULL) {
        nnode->near = bridge_cpy_array(node->near, node->namount);
        nnode->namount = node->namount;
    }
    return (nnode);
}

void pnode_destroy(void *node_p)
{
    pnode_t *node = node_p;

    if (node == NULL)
        return;
    pnode_free(&node);
}

void pnode_free(pnode_t **node_p)
{
    pnode_t *node = NULL;

    if (node_p == NULL || (*node_p) == NULL)
        return;
    node = (*node_p);
    pnode_detach(node);
    if (node->from != NULL)
        sdel(&node->from);
    (*node_p) = NULL;
}

int pnode_advance(pnode_t *node, list_t *list)
{
    pnode_t *c = NULL;
    int ret = 0;

    if (node == NULL || list == NULL)
        return (-1);
    for (uint_t i = 0; i < node->namount; i++) {
        spdestroy(c);
        c = pnode_copy_unexplored(node, i);
        if (c == NULL)
            continue;
        c->cost = node->near[i].score + node->cost;
        c->score += c->cost;
        c->from = spcopy(node);
        list_push_back(list, c);
        ret += 1;
    }
    spdestroy(c);
    return (ret);
}
