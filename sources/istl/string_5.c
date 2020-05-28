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

string_t *str_wcreate(char *cstr)
{
    string_t *nstr = malloc(sizeof(string_t));
    uint_t len = 0;

    if (cstr != 0)
        for (len = 0; cstr[len] != 0; len++);
    nstr->cstr = cstr;
    nstr->length = len;
    return (nstr);
}

void str_free(string_t **pstr)
{
    string_t *str = 0;

    if (pstr == 0 || *pstr == 0)
        return;
    str = *pstr;
    if (str->cstr != 0)
        free(str->cstr);
    free(str);
    *pstr = 0;
}

void str_strip(string_t *str)
{
    str_cnstrip(str, ' ', -1, -1);
}

void str_replace(string_t *str, char a, char b)
{
    if (str == NULL || str_cstr(str) == NULL)
        return;
    for (uint_t i = 0; i < str_len(str); i++) {
        if (str_cstr(str)[i] == a)
            str->cstr[i] = b;
    }
}

void str_cnstrip(string_t *str, char c, uint_t l, uint_t r)
{
    uint_t left = 0;
    uint_t right = 0;
    string_t *tmp = NULL;

    if (str == NULL)
        return;
    l -= 1;
    r = (r == (uint_t)(-1)) ? r : r + 1;
    for (; str_cstr(str)[left] == c; left++);
    right = str_len(str) - 1;
    for (; right != (uint_t)(-1) && str_cstr(str)[right] == c; right--);
    left = (left > l) ? l : left;
    right = ((str_len(str) - right) > r) ? str_len(str) - r : right;
    tmp = str_substr(str, left, right);
    str->cstr = tmp->cstr;
    str->length = tmp->length;
}
