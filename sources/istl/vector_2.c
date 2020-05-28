/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "istl/private/p_vector.h"

vector_t *vector_set(vector_t *vec, uint_t idx, void const *cdata)
{
    if (vec == NULL || idx > vector_len(vec))
        return (NULL);
    if (cdata == NULL) {
        vec->data[idx] = NULL;
        return (vec);
    }
    if (vec->tmeta.copy == NULL)
        vec->data[idx] = mem_copy(cdata, vec->tmeta.data_size);
    else
        vec->data[idx] = vec->tmeta.copy(cdata);
    return (vec);
}

void *vector_get(vector_t *vec, uint_t idx)
{
    if (vec == NULL || idx >= vector_len(vec))
        return (NULL);
    return (vec->data[idx]);
}

void const *vector_cget(vector_t const *cvec, uint_t idx)
{
    if (cvec == NULL || idx >= vector_len(cvec))
        return (NULL);
    return (cvec->data[idx]);
}

uint_t vector_len(vector_t const *cvec)
{
    if (cvec == NULL)
        return (0);
    return (cvec->size);
}
