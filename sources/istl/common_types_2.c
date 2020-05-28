/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include "istl/common_types.h"
#include <stdlib.h>

mcell_t *get_mcell(void *ptr)
{
    if (ptr == NULL)
        return (NULL);
    return (*(void **)ptr - sizeof(mcell_t));
}
