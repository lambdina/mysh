/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_iterator.h"

void it_swap(iterator_t *lhs, iterator_t *rhs)
{
    iterator_t *olhs = NULL;
    iterator_t *orhs = NULL;
    void *data = NULL;

    if (lhs == 0 || rhs == 0)
        return;
    data = lhs->data;
    lhs->data = rhs->data;
    rhs->data = data;
    olhs = lhs->first;
    orhs = rhs->first;
    if (olhs == NULL || orhs == NULL)
        return;
    olhs->data = lhs->data;
    orhs->data = rhs->data;
}

bool_t it_reach(iterator_t lhs, iterator_t rhs)
{
    if (lhs.layer_id == rhs.layer_id)
        return (TRUE);
    return (FALSE);
}

long long int it_distance(iterator_t lhs, iterator_t rhs)
{
    long long int i = 0;
    iterator_t trh = lhs;

    if (!it_reach(lhs, rhs))
        return (0);
    while (!it_eq(lhs, rhs) && !it_eq(trh, rhs)) {
        lhs = it_next(lhs);
        trh = it_back(trh);
        i += 1;
    }
    return (i);
}
