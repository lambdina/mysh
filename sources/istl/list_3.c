/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

void list_push_front(list_t *list, void *data)
{
    iterator_t *it = 0;
    dsize_t sizeof_data;
    cpy_constructor_ft copy;

    if (list == 0)
        return;
    copy = list->type_meta.copy;
    sizeof_data = list->type_meta.data_size;
    data = (copy == 0) ? mem_copy(data, sizeof_data) : copy(data);
    it = it_allocate(data, sizeof_data);
    it->next = list->begin;
    list->begin->prior = it;
    it->layer_id = list->begin->layer_id;
    list->begin = it;
    list->size += 1;
}

void list_pop_back(list_t *list)
{
    iterator_t *prior = NULL;
    iterator_t *it = NULL;
    void *data = NULL;

    if (list == NULL || list->size < 2) {
        if (list_len(list) == 1)
            list_pop_front(list);
        return;
    }
    it = it_get_prior(list->end);
    prior = it_get_prior(it);
    it_couple(prior, list->end);
    data = list_data(*it);
    if (list->type_meta.destroy == 0)
        free(data);
    else
        list->type_meta.destroy(data);
    it_free(&it);
    list->size -= 1;
}

void list_pop_front(list_t *list)
{
    iterator_t *it = 0;
    iterator_t *next = 0;
    void *data = 0;

    if (list == 0 || list->size < 1)
        return;
    it = list->begin;
    next = it_get_next(it);
    it_couple(0, next);
    data = list_data(*it);
    if (list->type_meta.destroy == 0)
        free(data);
    else
        list->type_meta.destroy(data);
    it_free(&it);
    list->begin = next;
    list->size -= 1;
}

void *list_pull(list_t *list, iterator_t it)
{
    iterator_t *prior = 0;
    iterator_t *next = 0;
    iterator_t *pit = 0;
    void *data = 0;

    if (list == 0 || it_eq(it, list_end(list)))
        return (0);
    if (!it_reach(list_begin(list), it))
        return (0);
    data = it_data(it);
    prior = it_get_prior(&it);
    next = it_get_next(&it);
    if (prior == 0)
        list->begin = next;
    pit = (prior == 0) ? it_get_prior(next) : it_get_next(prior);
    it_free(&pit);
    it_couple(prior, next);
    list->size -= 1;
    return (data);
}

iterator_t *list_get_begin(list_t *list)
{
    if (list == 0)
        return (0);
    return (list->begin);
}
