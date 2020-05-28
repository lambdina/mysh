/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef ISTL_ASTAR_PRIVATE_H_INCLUDED
#define ISTL_ASTAR_PRIVATE_H_INCLUDED

#include "istl/astar.h"

typedef struct Bridge {
    int score;
    wptr_t dest;
} (bridge_t);

typedef struct PathNode {
    unsigned int id;
    pnode_t *from;
    bool_t locked;
    int score;
    int cost;
    bool_t goal;
    unsigned int namount;
    bridge_t *near;
} (pnode_t);

int pnode_advance(pnode_t *node, list_t *list);
void pnode_backtrace(pnode_t *node, list_t *nodes);
bool_t pnode_further_then(iterator_t lhs, iterator_t rhs);
bool_t pnode_comes_from(pnode_t const *lhs, pnode_t const *rhs);

bridge_t *bridge_cpy_array(bridge_t const *, uint_t len);

void pnode_print(void *);

#endif
