/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#ifndef ISTL_SHARED_PTR_INCLUDED
#define ISTL_SHARED_PTR_INCLUDED

#include "istl/common_types.h"
#include "istl/utility.h"

void *shared_ptr(mdata_t tmeta);
void *spcopy(void const *ptr);
void spdestroy(void *ptr);
uint_t ref_count(void *ptr);
bool_t is_shared(void *ptr);

#endif
