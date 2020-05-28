/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_hash_table.h"

void *map_get(map_t *map, hash_value_t key)
{
    list_t *list = 0;
    iterator_t it;
    ht_item_t *item = 0;

    if (map == 0)
        return (0);
    list = map->data_table[key % map->array_size];
    it = list_begin(list);
    for (uint_t i = 0; i < list_len(list); i++, it = it_next(it)) {
        item = (ht_item_t *)list_data(it);
        if (item != 0 && item->key == key)
            return (item->value);
    }
    return (0);
}

list_t *map_get_all(map_t *map, hash_value_t key)
{
    list_t *list = 0;
    list_t *found = 0;
    iterator_t it;
    ht_item_t *item = 0;

    if (map == 0)
        return (0);
    list = map->data_table[key % map->array_size];
    it = list_begin(list);
    for (uint_t i = 0; i < list_len(list); i++, it = it_next(it)) {
        item = (ht_item_t *)list_data(it);
        if (item != 0 && item->key == key) {
            found = (found == 0) ? list_create(map->type_meta) : found;
            list_push_back(found, item->value);
        }
    }
    return (found);
}

void *map_pull(map_t *map, hash_value_t key)
{
    list_t *list = 0;
    iterator_t it;
    ht_item_t *item = 0;
    void *data = 0;

    if (map == 0)
        return (0);
    list = map->data_table[key % map->array_size];
    it = list_begin(list);
    for (uint_t i = 0; i < list_len(list); i++, it = it_next(it)) {
        item = (ht_item_t *)list_data(it);
        if (item->key == key) {
            item = list_pull(list, it);
            data = item->value;
            ht_item_free(&item);
            return (data);
        }
    }
    return (0);
}

void *map_erase(map_t *map, hash_value_t key, hash_value_t sign)
{
    list_t *list = 0;
    iterator_t it;
    ht_item_t *item = 0;

    if (map == 0)
        return (0);
    list = map->data_table[key % map->array_size];
    it = list_begin(list);
    for (uint_t i = 0; i < list_len(list); i++, it = it_next(it)) {
        item = (ht_item_t *)list_data(it);
        if (item->key == key)
            return (map_erase_item(list, it, sign, map->type_meta.data_size));
    }
    return (NULL);
}

uint_t map_count(map_t const *map)
{
    uint_t len = 0;
    list_t *current = 0;

    for (uint_t i = 0; i < map->array_size; i++) {
        current = map->data_table[i];
        len += list_len(current);
    }
    return (len);
}
