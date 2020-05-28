/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#include "common_types.h"
#include "iterator.h"
#include "list.h"

/*!
    \brief HashMap data tuple
    \details Structure containing a key associated to a
    data pointer. The HashMap container uses this for its
    internal organization
    \author Iaroslav Sorokin
*/
typedef struct HashTableItem {
    hash_value_t key;   //!< Numeric hash representation of key objects
    void *value;    //!< Generic pointer to associated data
} ht_item_t;

ht_item_t *ht_item_create(hash_value_t key, void *value); //!< \internal
void ht_item_free(ht_item_t **item); //!< \internal
void *ht_item_copy(void const *item); //!< \internal
void ht_item_destroy(void *item); //!< \internal

extern const meta_bundle_t MB_HT_ITEM; //!< HashMap type's infos

/*!
    \brief Classic HashMap data structure
    \details This data structure associates a number representation
    of an object to a data value, and allows to quickly access any
    data paired with any key. The key could be any type, as long
    as you use ```hash_data``` function to generate a hash, or
    ```hash_str``` shortcut for a string. Even though the HashMap
    has a size that you must give at the creation - it doesn't
    affect maximum storage size, it will only affect collision rate,
    and thus possibly create performance issues.
    \author Iaroslav Sorokin
*/
typedef struct HashMap
{
    unsigned int array_size;    //!< Amount of linked lists to data storage
    list_t **data_table;
    meta_bundle_t type_meta;
} map_t;

/*!
    \brief HashMap allocation method
    \details Allocates minimum necessary memory for the HashMap,
    even though it could grow over time, since it uses LinkedLists.
    Please get familiar with ```meta_bundle_t``` before using this.
*/
map_t *map_create(unsigned int size, meta_bundle_t meta);

/*!
    \brief C string hashing function
*/
hash_value_t hash_str(char const *str);

/*!
    \brief Custom data type hashing function
*/
hash_value_t hash_data(void const *data, dsize_t size);

/*!
    \brief HashMap resizing method
    \details This allows you to reallocate the existing HashMap
    and to re-store its elements.
    \todo Implement
*/
void map_resize(map_t *map, unsigned int size);
uint_t map_count(map_t const *map);

void map_insert(map_t *map, hash_value_t, void const *value);
void *map_get(map_t *map, hash_value_t);
list_t *map_get_all(map_t *map, hash_value_t);
void *map_pull(map_t *map, hash_value_t);
void *map_erase(map_t *map, hash_value_t, hash_value_t);
void const *map_cget(map_t const map, hash_value_t);
void map_drop(map_t *map);

void map_free(map_t **map);

#endif
