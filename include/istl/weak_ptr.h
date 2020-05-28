/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#ifndef ISTL_WEAK_PTR_INCLUDED
#define ISTL_WEAK_PTR_INCLUDED

#include "istl/common_types.h"
#include "istl/utility.h"

wptr_t wpcopy(wptr_t);
wptr_t make_weak(void *sp);
void *wptr_lock(wptr_t wp);
bool_t wptr_valid(wptr_t wp);

#endif
