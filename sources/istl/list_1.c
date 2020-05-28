/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

void list_revert(list_t *list)
{
    iterator_t it;
    list_t *nlist = 0;

    if (list == 0)
        return;
    it = list_begin(list);
    nlist = list_create(list->type_meta);
    for (it = list_begin(list); !list_final(list, it); it = it_next(it))
        list_push_front(nlist, list_data(it));
    while (list_len(list) != 0)
        list_pop_front(list);
    for (it = list_begin(nlist); !list_final(nlist, it); it = it_next(it))
        list_push_back(list, list_data(it));
}

void list_iswap(iterator_t lhs, iterator_t rhs)
{
    it_swap(&lhs, &rhs);
}

void list_sort(list_t *list, compare_ft cmp_fp)
{
    itr_t *i = NULL;
    itr_t *j = NULL;
    itr_t *n = NULL;

    if (list == NULL || cmp_fp == NULL || list_len(list) < 1)
        return;
    i = list_get_end(list);
    for (; !it_eq(*i, list_begin(list)); i = it_get_prior(i)) {
        if (!it_eq(*i, list_end(list)) && cmp_fp(*i, it_back(*i)) == FALSE)
            continue;
        j = list_get_begin(list);
        for (; !it_eq(it_back(*i), *j); j = n) {
            n = it_get_next(j);
            if (cmp_fp(*j, *n) == TRUE)
                it_swap(n, j);
        }
    }
}

void list_foreach(list_t *list, foreach_ft cb)
{
    iterator_t it;

    if (list == NULL || cb == NULL)
        return;
    it = list_begin(list);
    for (; !list_final(list, it); it = it_next(it))
        cb(it_data(it));
}

void list_drop(list_t *list)
{
    if (list == NULL)
        return;
    while (list_len(list) > 0)
        list_pop_back(list);
}
