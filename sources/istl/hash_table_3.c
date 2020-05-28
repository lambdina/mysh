/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_hash_table.h"

const meta_bundle_t MB_HT_ITEM = {
    ht_item_copy,
    ht_item_destroy,
    sizeof(ht_item_t)
};


static void free_item_content(ht_item_t *item, destructor_ft destroy)
{
    if (item == 0)
        return;
    if (destroy == 0)
        free(item->value);
    else
        destroy(item->value);
}

void map_free(map_t **pmap)
{
    ht_item_t *item;
    iterator_t it;
    uint_t llen;

    if (pmap == 0 || *pmap == 0)
        return;
    for (uint_t i = 0; i < (*pmap)->array_size; i++) {
        it = list_begin((*pmap)->data_table[i]);
        llen = list_len((*pmap)->data_table[i]);
        for (uint_t j = 0; j < llen; j++, it = it_next(it)) {
            item = (ht_item_t *)list_data(it);
            free_item_content(item, (*pmap)->type_meta.destroy);
        }
        list_free(&(*pmap)->data_table[i]);
    }
    free((*pmap)->data_table);
    free(*pmap);
    (*pmap) = 0;
}

ht_item_t *ht_item_create(hash_value_t key, void *value)
{
    ht_item_t *item = malloc(sizeof(ht_item_t));

    item->key = key;
    item->value = value;
    return (item);
}

void ht_item_free(ht_item_t **item)
{
    if (item == 0 || (*item) == 0)
        return;
    free(*item);
    (*item) = 0;
}

void *ht_item_copy(void const * item)
{
    ht_item_t *old = (ht_item_t *)item;
    ht_item_t *nitem = 0;

    if (old == 0)
        return (0);
    nitem = ht_item_create(old->key, old->value);
    return (nitem);
}
