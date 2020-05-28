/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef PRIVATE_OBSERVABLE_H_INCLUDED
#define PRIVATE_OBSERVABLE_H_INCLUDED

#include "istl/common_types.h"
#include "istl/list.h"
#include "istl/observable.h"

extern const mdata_t MB_OBSR;

typedef struct Observer {
    void *ptr;
    obs_callback_ft callback;
} (observer_t);

typedef struct Observable {
    list_t *subscribers;
} (observable_t);

#endif
