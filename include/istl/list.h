/*
** EPITECH PROJECT, 2019
** Mon titre
** File description:
** Description
*/
#ifndef IS_CHAINED_LIST_H_INCLUDED
#define IS_CHAINED_LIST_H_INCLUDED

#include "common_types.h"
#include "iterator.h"

extern const meta_bundle_t MB_INT;
extern const meta_bundle_t MB_FLOAT;
extern const meta_bundle_t MB_DOUBLE;
extern const meta_bundle_t MB_CHAR;
extern const meta_bundle_t MB_PTR;
extern const meta_bundle_t MB_BOOL;

typedef bool_t (*compare_ft)(iterator_t lhs, iterator_t rhs);
typedef void (*foreach_ft)(void *data);

/*!
    \brief Bidirectional linked list class
    \details This class represents a data container
    with undefined and flexible size, but
    with no random access possibility. Various
    functions allow to iterater through the
    list to get the needed element, but
    you can't directly access an element by,
    let's say, its index, like in a vector array.
    \author Iaroslav Sorokin
*/
typedef struct LinkedList {
    unsigned int size;
    iterator_t *begin;
    iterator_t *end;
    meta_bundle_t type_meta;
} list_t;

/*!
    Method that allocates memory
    for the object. Beware, this is only
    reserving memory for list_t struct,
    but not for the entire container. The
    rest is allocated on every insert operation,
    if copy constructor is provided.
*/
list_t *list_create(meta_bundle_t type_infos);

/*!
    This method makes a copy of the entire list
    towards a new list. Copies of each and every
    stored element are maid, howerer is these are
    deep copies, or not depends on provided copy
    constructor and destructor.
*/
list_t *list_copy(list_t *list);

/*!
    Merge method allows to fill the first given
    list with the elements of the second one. All
    the elements are copied from the second one
    **to** the first one, so the second is left
    untouched
    \todo Make second parameter ```const```
*/
void list_merge(list_t *lhs, list_t *rhs);

/*!
    Method returns the very iterator pointer
    used by the list itself, pointing at the
    beginning. This should never be used by a
    client code, it's only necessary in some
    internal cases.
*/
iterator_t *list_get_begin(list_t *list);

/*!
    Method returns the very iterator pointer
    used by the list itself, pointing at the
    end. This should never be used by a
    client code, it's only necessary in some
    internal cases.
*/
iterator_t *list_get_end(list_t *list);

/*!
    Method that allows you to obtain somewhat of
    a pointer to the begginning of the list, that
    can be manipulated by other list functions.
*/
iterator_t list_begin(list_t *list);

/*!
    Method that allows you to obtain somewhat of
    a pointer to the end of the list, that
    can be manipulated by other list functions.
*/
iterator_t list_end(list_t *list);

/*!
    Tests whether or not the given iterator points
    at the **end** of a list.
*/
bool_t list_final(list_t *list, iterator_t it);

/*!
    Tests whether or not the given iterator points
    at the **beginning** of a list.
*/
bool_t list_start(list_t *list, iterator_t it);

/*!
    Allows you to get the len of a list without
    accessing its internal variable. Returns
    0 if ```list``` is a null pointer.
*/
unsigned int list_len(list_t const *list);

/*!
    An iterator handle to get data stored within
*/
void *list_data(iterator_t it);

/*!
    This function inserts an element's **copy**
    at the **end** of the given list. Resistant to
    null ```list``` pointer. Stores data any if
    ```data == 0```
*/
void list_push_back(list_t *list, void const *data);

/*!
    This function inserts an element's **copy**
    at the **beginning** of the given list. Resistant to
    null ```list``` pointer. Stores data any if
    ```data == 0```
*/
void list_push_front(list_t *list, void *data);

/*!
    Allows to erase the element at the end of the list.
    Deep free depends on the provided **destructor**.
*/
void list_pop_back(list_t *list);

/*!
    Allows to erase the element at the beginning of the list.
    Deep free depends on the provided **destructor**.
*/
void list_pop_front(list_t *list);

/*!
    Allows to transfer ownership of an element directly
    to the client code. The element is howered erased from
    the list, but **is not** freed, so the client code
    will have to free it itself.
*/
void *list_pull(list_t *list, iterator_t it);

/*!
    Allows to swap to elements pointed by given iterators
    \todo Check internal behaviour and give better
    description
*/
void list_iswap(iterator_t lhs, iterator_t rhs);

/*!
    Allocates new list and copies each and every element
    between ```begin``` and ```end```
    \todo Check if ```end``` is included (copied too).
*/
list_t *list_splice(list_t *list, iterator_t begin, iterator_t end);

/*!
    Completely reverses list order
    \todo Optimize the whole process. It still creates
    a new list and re-inserts every element. Also,
    ```nlist``` within is never freed.
*/
void list_revert(list_t *list);

void list_drop(list_t *list);

/*!
    Takes a double pointer on a list and frees all the
    memory, thus each and every element. Deep free depends
    on the provided destructor (if custom object used).
*/
void list_free(list_t **plist);

void list_sort(list_t *list, compare_ft);

void list_foreach(list_t *list, foreach_ft);

/*!
    Returns a copy of the entire list as an array of
    elements. Deep copy depends on the provided type
    copy constructor. Conversions are on the client code since
    we're not in C++ here. What d you expect?
*/
void **list_to_array(list_t *list);

#endif
