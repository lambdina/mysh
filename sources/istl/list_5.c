/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_list.h"
#include "istl/utility.h"

void list_free(list_t **plist)
{
    list_t *list = *plist;
    iterator_t *it = list_get_begin(list);
    iterator_t *end = list_get_end(list);
    iterator_t *tmp = 0;
    void *data = 0;

    if (plist == 0 || *plist == 0)
        return;
    for (;it != end; it = tmp) {
        tmp = it_get_next(it);
        data = list_data(*it);
        if (list->type_meta.destroy == 0)
            free(data);
        else
            list->type_meta.destroy(data);
        it_free(&it);
    }
    it_free(&it);
    free(list);
    *plist = 0;
}

bool_t list_final(list_t *list, iterator_t it)
{
    return (it_eq(it, list_end(list)));
}

bool_t list_start(list_t *list, iterator_t it)
{
    return (it_eq(it, list_begin(list)));
}

list_t *list_splice(list_t *list, iterator_t begin, iterator_t end)
{
    list_t *nlist = 0;

    if (list == 0)
        return (0);
    nlist = list_create(list->type_meta);
    for (iterator_t it = begin; !it_eq(it, end); it = it_next(it))
        list_push_back(nlist, list_data(it));
    return (nlist);
}

void *mem_copy(void const *data, dsize_t size)
{
    void *ndata = malloc(size);
    byte_t *byte = (byte_t *)ndata;

    for (dsize_t i = 0; i < size; i++) {
        *(byte + i) = *((byte_t *)data + i);
    }
    return (ndata);
}

