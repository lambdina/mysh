/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/private/p_vector.h"

vector_t *vector_from_list(list_t *list)
{
    vector_t *vec = NULL;
    itr_t it;

    if (list == NULL)
        return (NULL);
    vec = vector_create(list->type_meta);
    it = list_begin(list);
    for (; !list_final(list, it); it = it_next(it))
        vector_push(vec, it_data(it));
    return (vec);
}

int vector_narrow(vector_t *vec)
{
    void **data = NULL;
    uint_t c = 0;

    if (vec == NULL)
        return (-1);
    data = malloc(sizeof(void *) * vec->capacity);
    for (uint_t i = 0; i < vec->capacity; i++) {
        data[i] = NULL;
        if (vector_get(vec, i) == NULL)
            continue;
        data[c] = vec->data[i];
        c += 1;
    }
    free(vec->data);
    vec->data = data;
    vec->size = c;
    return (0);
}
