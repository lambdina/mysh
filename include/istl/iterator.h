/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef IS_ITERATOR_H_INCLUDED
#define IS_ITERATOR_H_INCLUDED

#include "common_types.h"

/*!
    \brief Data pointer wrapper
    \details An iterator is like a pointer to
    a generic data, but it also provides
    some mechanisms to protect client
    data structure from being accessed
    at wrong position, or else. This is
    especially useful for a linked list. You
    can access its stored data at any time
    via ```it_data```.
*/
typedef struct Iterator {
    void *data;
    int layer_id;
    unsigned int data_size;
    unsigned long long hash;
    struct Iterator *next;
    struct Iterator *prior;
    struct Iterator *first;
} iterator_t;
typedef struct Iterator (itr_t);

/*!
    Creates an iterator **without** allocating it
    in your RAM, only on stack. This approach allows
    to avoid heavy pointer syntax and manipulate with
    your structures in a safe way.
    \todo Check if size of the data must be stored in an
    iterator. It may be useless since an iterator is
    **not** responsible of it's data.
*/
__attribute__((deprecated("Use it_allocate instead.")))
iterator_t it_create(void *data, unsigned int sizeof_data);

/*!
    Forces the iterator RAM allocation.
*/
iterator_t *it_allocate(void *data, unsigned int sizeof_data);

/*!
    Allows to compare 2 different iterators.
*/
bool_t it_eq(iterator_t lhs, iterator_t rhs);

/*!
    Chechs whether or not the iterator is conscious
    of its **following** iterator
*/
bool_t it_has_next(iterator_t it);

/*!
    Chechs whether or not the iterator is conscious
    of its **preceeding** iterator
*/
bool_t it_has_prior(iterator_t it);

/*!
    Checks whether or not two iterators can reach
    each other through iterations. Usefull to test
    an iterator validity, and to know if two
    iterators are a part of the same container.
*/
bool_t it_reach(iterator_t lhs, iterator_t rhs);

/*!
    Returns the next iterator if any, or the
    iterator itself otherwise.
*/
iterator_t it_next(iterator_t it);

/*!
    Returns the previous iterator if any, or the
    iterator itself otherwise.
*/
iterator_t it_back(iterator_t it);

/*!
    Direct pointer access to the next iterator. You
    shouldn't use this function in your client code
    \deprecated use ```it_next``` for client code instead
*/
iterator_t *it_get_next(iterator_t *it);

/*!
    Direct pointer access to the previous iterator. You
    shouldn't use this function in your client code
    \deprecated use ```it_back``` for client code instead
*/
iterator_t *it_get_prior(iterator_t *it);

/*!
    Reserved for internal use only by data holders.
    \deprecated Use it only when implementing a data container
*/
void it_set_next(iterator_t *lhs, iterator_t *rhs);

/*!
    Reserved for internal use only by data holders.
    \deprecated Use it only when implementing a data container
*/
void it_set_prior(iterator_t *lhs, iterator_t *rhs);

/*!
    Reserved for internal use only by data holders. Allows
    to couple two iterators one to another. **Beware**: the
    actual iterator order matters.
    \deprecated Use it only when implementing a data container
*/
void it_couple(iterator_t *lhs, iterator_t *rhs);

/*!
    Allows to swap iterators' data
*/
void it_swap(iterator_t *lhs, iterator_t *rhs);

/*!
    Allows to mesure how many elements are stored
    between two iterators
*/
long long int it_distance(iterator_t lhs, iterator_t rhs);
iterator_t it_advance(iterator_t it, int rhs);

/*!
    Allows to access iterator's uncasted generic data.
*/
void *it_data(iterator_t it);

/*!
    Allows to free an iterator. **Beware**: no deep free
    mechanisms provided, since an iterator knows nothing
    about its stored type's internal structure.
*/
void it_free(iterator_t **it);

#endif
