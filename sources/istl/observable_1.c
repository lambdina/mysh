/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include "istl/private/p_observable.h"

const mdata_t MB_OBSR = {
    .copy = NULL,
    .destroy = NULL,
    .data_size = sizeof(observer_t)
};

observable_t *obs_create(void)
{
    observable_t *obs = malloc(sizeof(observable_t));

    obs->subscribers = list_create(MB_OBSR);
    return (obs);
}

void obs_free(observable_t **obs_p)
{
    observable_t *obs = NULL;

    if (obs_p == NULL || (*obs_p) == NULL)
        return;
    obs = (*obs_p);
    list_free(&obs->subscribers);
    free(obs);
}

int obs_subscribe(
        observable_t *obs,
        void *observer_p,
        obs_callback_ft cb)
{
    observer_t obsr = (observer_t) {
        .ptr = observer_p,
        .callback = cb
    };

    if (obs == NULL || observer_p == NULL || cb == NULL)
        return (-1);
    list_push_back(obs->subscribers, &obsr);
    return (0);
}

int obs_notify(observable_t *obs_p, void *robs, int sig)
{
    iterator_t it;
    observer_t *obsr = NULL;

    if (obs_p == NULL)
        return (-1);
    it = list_begin(obs_p->subscribers);
    for (; !list_final(obs_p->subscribers, it); it = it_next(it)) {
        obsr = list_data(it);
        obsr->callback(obsr->ptr, robs, sig);
    }
    return (0);
}

int obs_unsubscribe(observable_t *obs_p, void *obsr_p)
{
    iterator_t it;
    observer_t *obsr = NULL;

    if (obs_p == NULL || obsr_p == NULL)
        return (-1);
    it = list_begin(obs_p->subscribers);
    for (; !list_final(obs_p->subscribers, it); it = it_next(it)) {
        obsr = list_data(it);
        if (obsr->ptr == obsr_p)
            list_pull(obs_p->subscribers, it);
    }
    return (0);
}
