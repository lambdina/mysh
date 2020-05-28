/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_iterator.h"

iterator_t *it_get_prior(iterator_t *it)
{
    return (it->prior);
}

void it_set_next(iterator_t *lhs, iterator_t *rhs)
{
    if (lhs == 0)
        return;
    lhs->next = rhs;
    if (rhs != 0)
        rhs->layer_id = lhs->layer_id;
}

void it_set_prior(iterator_t *lhs, iterator_t *rhs)
{
    if (lhs == 0)
        return;
    lhs->prior = rhs;
    if (rhs != 0)
        lhs->layer_id = rhs->layer_id;
}

void it_couple(iterator_t *lhs, iterator_t *rhs)
{
    if (lhs != 0)
        it_set_next(lhs, rhs);
    if (rhs != 0)
        it_set_prior(rhs, lhs);
}

void it_free(iterator_t **pit)
{
    iterator_t *it = *pit;

    free(it);
    *pit = 0;
}
