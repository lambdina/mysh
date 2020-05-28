/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef ISTL_VECTOR_PRIVATE_H_INCLUDED
#define ISTL_VECTOR_PRIVATE_H_INCLUDED

#include "istl/common_types.h"
#include "istl/utility.h"
#include "istl/vector.h"

extern const mdata_t MB_VECTOR;

typedef struct Vector {
    void **data;
    uint_t size;
    uint_t capacity;
    mdata_t tmeta;
} (vector_t);

uint_t vector_expand(vector_t *vec);

void vector_qs(vector_t *vec, vsorter_ft sorter, uint_t lb, uint_t rb);

#endif
