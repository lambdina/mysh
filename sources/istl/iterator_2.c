/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_iterator.h"

unsigned long long get_unique_id(void)
{
    static unsigned long long id = 0;

    return (id++);
}

iterator_t it_create(void *data, unsigned int sizeof_data)
{
    unsigned long long id = get_unique_id();
    iterator_t it;

    it.first = NULL;
    it.data = data;
    it.data_size = sizeof_data;
    it.hash = id;
    it.next = 0;
    it.prior = 0;
    it.layer_id = id;
    return (it);
}

iterator_t *it_allocate(void *data, unsigned int sizeof_data)
{
    iterator_t *it = malloc(sizeof(iterator_t));

    it->first = it;
    it->data = data;
    it->data_size = sizeof_data;
    it->hash = get_unique_id();
    it->next = NULL;
    it->prior = NULL;
    it->layer_id = it->hash;
    return (it);
}

bool_t it_eq(iterator_t lhs, iterator_t rhs)
{
    if (lhs.hash == rhs.hash)
        return (TRUE);
    return (FALSE);
}

void *it_data(iterator_t it)
{
    return (it.data);
}
