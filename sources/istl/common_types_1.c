/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include "istl/common_types.h"
#include "istl/shared_ptr.h"
#include <stdlib.h>

const meta_bundle_t MB_INT = {0, 0, sizeof(int)};
const meta_bundle_t MB_FLOAT = {0, 0, sizeof(float)};
const meta_bundle_t MB_DOUBLE = {0, 0, sizeof(double)};
const meta_bundle_t MB_CHAR = {0, 0, sizeof(char)};
const meta_bundle_t MB_PTR = {0, 0, sizeof(int *)};
const meta_bundle_t MB_BOOL = {0, 0, sizeof(bool_t)};
const meta_bundle_t MB_SPTR = {
    .copy = spcopy,
    .destroy = spdestroy
};
const vec2_t V_NULL = {.x = 0, .y = 0};


__attribute__((malloc)) void *snew(mdata_t m)
{
    mcell_t *mcell = malloc(sizeof(mcell_t) + m.data_size);

    if (mcell == NULL)
        return (NULL);
    *mcell = (mcell_t) {
        .type = SP_UNIQUE,
        .count = NULL,
        .wcount = NULL,
        .dtor = m.destroy,
        .data = mcell + 1
    };
    return (mcell->data);
}

__attribute__((always_inline))
inline void sdel_unique(mcell_t *mcell)
{
    if (mcell->dtor != 0)
        mcell->dtor(mcell->data);
    free(mcell);
}

__attribute__((always_inline))
inline void sdel_shared(mcell_t *mcell)
{
    if (*mcell->count <= 1) {
        if (*mcell->wcount == 0) {
            free(mcell->wcount);
            free(mcell->count);
        }
        else
            *mcell->count = 0;
        sdel_unique(mcell);
    } else
        *mcell->count -= 1;
}

__attribute__((always_inline))
inline void sdel_weak(wptr_t ptr)
{
    mcell_t *mcell = ptr;

    if (mcell == NULL)
        return;
    if (*mcell->count == 0 && *mcell->wcount == 1) {
        free(mcell->count);
        free(mcell->wcount);
    } else
        *mcell->wcount -= 1;
}

void sdel(void *data)
{
    mcell_t *mcell = get_mcell(data);

    if (data == NULL || *(void **)data == NULL)
        return;
    if (*(void **)data != mcell->data)
        return;
    switch (mcell->type) {
        case SP_UNIQUE:
            sdel_unique(mcell);
            break;
        case SP_SHARED:
            sdel_shared(mcell);
            break;
        case SP_WEAK:
            sdel_weak(mcell);
            break;
    }
}
