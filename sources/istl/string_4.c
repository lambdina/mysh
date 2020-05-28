/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <unistd.h>
#include "istl/string.h"
#include "istl/utility.h"

cchar_t str_cstr(string_t const *str)
{
    if (str == NULL)
        return (NULL);
    return (cchar_t)(str->cstr);
}

char *str_to_cstr(string_t const *str)
{
    char *nstr = 0;

    if (str == 0)
        return (0);
    nstr = malloc(sizeof(char) * (str->length + 1));
    for (uint_t i = 0; i < str->length; i++)
        nstr[i] = str->cstr[i];
    nstr[str->length] = 0;
    return (nstr);
}

string_t *str_dup(string_t const *str)
{
    string_t *nstr = 0;

    if (str == 0)
        return (0);
    nstr = str_create(str_cstr(str));
    return (nstr);
}

static uint_t max_len(uint_t lhs, uint_t rhs)
{
    return ((lhs > rhs) ? lhs : rhs);
}

string_t *str_concat(string_t const *lhs, string_t const *rhs)
{
    uint_t len1;
    uint_t len2;
    char *ncstr = 0;
    uint_t cr = 0;

    if (lhs == 0 && rhs == 0)
        return (0);
    len1 = (lhs == 0) ? 0 : str_len(lhs);
    len2 = (rhs == 0) ? 0 : str_len(rhs);
    ncstr = malloc(sizeof(char) * (len1 + len2 + 1));
    for (uint_t i = 0; i < max_len(len1, len2); i++, cr++) {
        if (i < len1)
            ncstr[cr] = str_cstr(lhs)[i];
        if (i < len2)
            ncstr[cr + len1] = str_cstr(rhs)[i];
    }
    ncstr[len1 + len2] = 0;
    return (str_wcreate(ncstr));
}
