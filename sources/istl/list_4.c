/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

iterator_t *list_get_end(list_t *list)
{
    if (list == 0)
        return (0);
    return (list->end);
}

void *list_data(iterator_t it)
{
    return (it_data(it));
}

iterator_t list_begin(list_t *list)
{
    return (*list->begin);
}

iterator_t list_end(list_t *list)
{
    return (*list->end);
}

unsigned int list_len(list_t const *list)
{
    if (list == 0)
        return (0);
    return (list->size);
}
