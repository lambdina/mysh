/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_hash_table.h"

static hash_value_t hash_str_data(cchar_t str, uint_t len)
{
    hash_value_t hash = 47441;

    for (uint_t i = 0; i < len; i++)
        hash = ((hash << 5) + hash) + str[i];
    return (hash);
}

hash_value_t hash_str(char const *str)
{
    hash_value_t hash = 47441;
    char c;

    while (*str) {
        c = *str;
        hash = ((hash << 5) + hash) + c;
        str++;
    }
    return (hash);
}

hash_value_t hash_data(void const *data, dsize_t size)
{
    char *as_str = 0;
    cchar_t nstr = (cchar_t)data;
    hash_value_t res = 0;

    if (data == 0)
        return (0);
    as_str = malloc(sizeof(char) * (size + 1));
    for (uint_t i = 0; i < size; i++)
        as_str[i] = nstr[i];
    as_str[size] = 0;
    res = hash_str_data(as_str, size + 1);
    free(as_str);
    return (res);
}

map_t *map_create(unsigned int size, meta_bundle_t meta)
{
    map_t *map = malloc(sizeof(map_t));

    map->type_meta = meta;
    map->array_size = size;
    map->data_table = malloc(sizeof(list_t *) * size);
    for (uint_t i = 0; i < size; i++)
        map->data_table[i] = list_create(MB_HT_ITEM);
    return (map);
}

void map_insert(map_t *map, hash_value_t key, void const *value)
{
    ht_item_t *nitem = 0;
    list_t *list = 0;
    void *copy = 0;

    if (map == 0)
        return;
    if (map->type_meta.copy == 0)
        copy = mem_copy(value, map->type_meta.data_size);
    else
        copy = map->type_meta.copy(value);
    nitem = ht_item_create(key, copy);
    key = key % map->array_size;
    list = map->data_table[key];
    list_push_back(list, nitem);
    ht_item_free(&nitem);
}
