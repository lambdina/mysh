/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_iterator.h"

bool_t it_has_next(iterator_t it)
{
    if (it.next != 0)
        return (TRUE);
    return (FALSE);
}

bool_t it_has_prior(iterator_t it)
{
    if (it.prior != 0)
        return (TRUE);
    return (FALSE);
}

iterator_t it_next(iterator_t it)
{
    if (it.next != 0)
        return (*it.next);
    return (it);
}

iterator_t it_back(iterator_t it)
{
    if (it.prior != 0)
        return (*it.prior);
    return (it);
}

iterator_t *it_get_next(iterator_t *it)
{
    return (it->next);
}
