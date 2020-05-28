/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef ISTL_VECTOR_H_INCLUDED
#define ISTL_VECTOR_H_INCLUDED

#include "istl/list.h"

typedef struct Vector (vector_t);
typedef bool_t (*vsorter_ft)(void const *lhs, void const *rhs);

vector_t *vector_create(mdata_t type);
void vector_free(vector_t **vec);
void vector_destroy(void *);
void *vector_copy(void const *);

vector_t *vector_set(vector_t *, uint_t, void const *);
void *vector_get(vector_t *, uint_t);
void const *vector_cget(vector_t const *, uint_t);
uint_t vector_len(vector_t const *);

vector_t *vector_push(vector_t *, void const *);
vector_t *vector_pop(vector_t *);
void *vector_pull(vector_t *, uint_t);
int vector_iswap(vector_t *, uint_t, uint_t);
int vector_narrow(vector_t *);

void vector_sort(vector_t *, vsorter_ft);

/*!
    \todo Optimize
*/
vector_t *vector_from_list(list_t *);

#endif
