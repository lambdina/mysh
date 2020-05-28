/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_vector.h"

vector_t *vector_pop(vector_t *vec)
{
    void *data = NULL;

    if (vec == NULL)
        return (NULL);
    data = vector_pull(vec, vector_len(vec) - 1);
    vec->size -= 1;
    if (vec->tmeta.destroy != NULL)
        vec->tmeta.destroy(data);
    else
        free(data);
    return (vec);
}
