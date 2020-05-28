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

static bool_t astar_step(list_t *queue)
{
    pnode_t *node = NULL;

    if (queue == NULL)
        return (FALSE);
    node = list_pull(queue, list_begin(queue));
    if (node->goal == TRUE) {
        list_drop(queue);
        pnode_backtrace(node, queue);
        spdestroy(node);
        return (TRUE);
    }
    pnode_advance(node, queue);
    spdestroy(node);
    list_sort(queue, pnode_further_then);
    return (FALSE);
}
