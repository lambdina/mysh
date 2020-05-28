/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include <stdlib.h>
#include "istl/weak_ptr.h"
#include "istl/shared_ptr.h"

wptr_t make_weak(void *sp)
{
    mcell_t *mcell = get_mcell(&sp);
    mcell_t *wp = snew((mdata_t){
        .copy = NULL,
        .destroy = sdel_weak,
        .data_size = sizeof(mcell_t)
    });

    wp->type = SP_WEAK;
    wp->wcount = mcell->wcount;
    *wp->wcount += 1;
    wp->count = mcell->count;
    wp->data = mcell->data;
    return (wp);
}

wptr_t wpcopy(wptr_t ptr)
{
    void *data = NULL;
    wptr_t ret = NULL;

    if (ptr == NULL || !wptr_valid(ptr))
        return (NULL);
    data = wptr_lock(ptr);
    ret = make_weak(data);
    sdel(&data);
    return (ret);
}

void *wptr_lock(wptr_t ptr)
{
    mcell_t *wp = ptr;

    if (wp == NULL || *wp->count == 0)
        return (NULL);
    return (spcopy(wp->data));
}

bool_t wptr_valid(wptr_t ptr)
{
    mcell_t *wp = ptr;

    if (wp == NULL)
        return (FALSE);
    if (*wp->count == 0)
        return (FALSE);
    return (TRUE);
}
