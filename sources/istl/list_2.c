/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

list_t *list_create(meta_bundle_t meta)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return (NULL);
    list->size = 0;
    list->begin = it_allocate(0, 0);
    list->end = list->begin;
    list->type_meta = meta;
    it_couple(list->begin, list->end);
    return (list);
}

void **list_to_array(list_t *list)
{
    unsigned int size;
    dsize_t dsize;
    void **array = 0;
    iterator_t it;

    if (list == 0 || list_len(list) < 1)
        return (0);
    it = list_begin(list);
    dsize = list->type_meta.data_size;
    size = list_len(list);
    array = (void **)malloc(sizeof(void *) * size);
    for (int i = 0; !list_final(list, it); i++) {
        if (list->type_meta.copy == 0)
            array[i] = mem_copy(list_data(it), dsize);
        else
            array[i] = list->type_meta.copy(list_data(it));
        it = it_next(it);
    }
    return (array);
}

list_t *list_copy(list_t *list)
{
    iterator_t begin;
    iterator_t end;
    list_t *nlist;

    if (list == 0)
        return (0);
    begin = list_begin(list);
    end = list_end(list);
    nlist = list_splice(list, begin, end);
    nlist->type_meta = list->type_meta;
    return (nlist);
}

void list_merge(list_t *lhs, list_t *rhs)
{
    iterator_t begin;

    if (lhs == 0 || rhs == 0)
        return;
    begin = list_begin(rhs);
    for (iterator_t it = begin; !list_final(rhs, it); it = it_next(it))
        list_push_back(lhs, list_data(it));
}

void list_push_back(list_t *list, void const *data_p)
{
    iterator_t *it = 0;
    dsize_t sizeof_data;
    void *data = NULL;
    cpy_constructor_ft copy;

    if (list == 0)
        return;
    copy = list->type_meta.copy;
    sizeof_data = list->type_meta.data_size;
    data = (copy == 0) ? mem_copy(data_p, sizeof_data) : copy(data_p);
    it = it_allocate(data, sizeof_data);
    if (list->size == 0) {
        list->begin = it;
        it_couple(list->begin, list->end);
    } else {
        it_couple(it_get_prior(list->end), it);
        it_couple(it, list->end);
    }
    list->size += 1;
}
