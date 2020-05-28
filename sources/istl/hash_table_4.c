/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_hash_table.h"

void ht_item_destroy(void *item)
{
    ht_item_t *tmp = (ht_item_t *)item;

    ht_item_free(&tmp);
}

void *map_erase_item(
        list_t *list,
        iterator_t it,
        hash_value_t sign,
        dsize_t size)
{
    hash_value_t dhash;
    void *data = NULL;
    ht_item_t *item = NULL;

    item = (ht_item_t *)list_data(it);
    dhash = hash_data(item->value, size);
    if (dhash == sign) {
        item = list_pull(list, it);
        data = item->value;
        ht_item_free(&item);
        return (data);
    }
    return (NULL);
}

void map_drop(map_t *map)
{
    uint_t size;

    if (map == NULL)
        return;
    size = map->array_size;
    for (uint_t i = 0; i < size; i++)
        list_drop(map->data_table[i]);
}
